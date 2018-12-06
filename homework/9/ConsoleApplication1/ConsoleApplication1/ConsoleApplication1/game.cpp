#include "stdafx.h"
#include "game.h"
#include "rand.h"
#include <cstring>
#include<cstdio>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#define SPEED 1 /*�Զ������� ��*/
#define PENAL_SIZE (17*24*sizeof(int)) /*��������С*/
#define CUBE_SIZE (3*3*sizeof(int)) /*������״��С*/

int num = 0;

static int stop_flag;
//Ϊ��ֻ����srand����һ�Σ�����ʱ�����������������Ͳ����ظ�
static Rand r;

/////////////////////////////////////////////
void Game::printNextCube(Context* graph) /*��һ����״*/
{
int x = 7;
int y = 19;
    int i,j;
   Cur c;
    CubePoint p;   

c.saveCur();
   c.moveCur(6,19);
   cout<<"next : ";
   c.resumeCur();

    int a[3][3] = {0};  //��ȡ��������
    memcpy(a,graph->getArray(),CUBE_SIZE);
    for(i = x; i < x+3; i++)
        for(j = y; j < y+3; j++)
        {       p.setLocate(i,j);
		p.setColor(CLEAR);
                p.printPoint();
            if(a[i - x][j - y] == 1)
            {

                p.setColor(graph->getColor());
                p.printPoint();
            }
        }
}

void Game::printHelep() /*�Ҳ���ʾ��Ϣ*/
{
   	Cur c;
	c.saveCur();
   	c.moveCur(10,19);
   	cout<<"a: go to left" << endl;
c.resumeCur();
c.saveCur();
   	c.moveCur(11,19);
   	cout<<"d: go to right" << endl;
c.resumeCur();
c.saveCur();
   	c.moveCur(12,19);
   	cout<<"w: roll cube" << endl;
c.resumeCur();
c.saveCur();
   	c.moveCur(13,19);
   	cout<<"s: go to down" << endl;
c.resumeCur();
c.saveCur();
   	c.moveCur(14,19);
   	cout<<"p: run or pause" << endl;
c.resumeCur();
}

void Game::gameInit()/*game ��ʼ��*/
{
    /*��ӡ˵��*/
	printHelep();
    /*Ԥ����һ��������״*/
	nextGraph = new Context(getShape());
	nextGraph->draw();/*?�����õ����麯�� virtual*/
	nextGraph->setLocate(1,7);
    /*������״*/
	createCube();
}

MARK Game::getMark() /*��ȡ��Ϸ״̬*/
{
	return mark;
}
void Game::setMark( MARK mark )/*������Ϸ״̬*/
{
	this->mark = mark;
}

Game::~Game()/*game ����*/
{
	if( NULL != m_graph )
	{
		delete m_graph;
		m_graph = NULL;
	}

	if( NULL != nextGraph )
	{
		delete nextGraph;
		nextGraph = NULL;
	}
}

//////////////////////////////////////////////

Game::Game()/*game ����*/
{
    m_graph = NULL;
    x = 1;
    y = 7;
    CubePoint p;
    int i;
    s.printMessage();//��ӡ��Ϣ

	mark = GAME_RUN;////////////////////////////////////////////////

    memset((void*)m_penal,0,PENAL_SIZE); //����ʼ��
	memset((void*)m_color,0,PENAL_SIZE); //color��ʼ��
   for(i = 0; i < 24; i++)//���Ʊ߿�
   {
        p.setLocate(i,0);
        p.setColor(BLUE);
        p.printPoint();
        p.setLocate(i,16);
        p.setColor(BLUE);
        p.printPoint();
        m_penal[i][0] = 1; //ǽ
        m_penal[i][16] = 1;//ǽ
   }
   for(i = 0; i < 17; i++) //���Ʊ߿�
   {
        p.setLocate(23,i);
        p.setColor(BLUE);
        p.printPoint();
        p.setLocate(0,i);
        p.setColor(RED);
        p.printPoint();
        m_penal[23][i] = 1;//ǽ
        m_penal[0][i] = 1; //ǽ
   }
   /*�������ֵ�Ƿ�����
   for(i = 0; i < 24; i++)
   {
        for(int j = 0; j < 17; j++)
            cout << m_penal[i][j] <<" ";
        cout << endl;
   }
   */
   fflush(stdout);
}

char Game::getShape()/*��÷�����״*/
{
    char ch;
    switch(r.randNum(1,6))
    {
        case 1:ch = 'Z';break;
        case 2:ch = 'T';break;
        case 3:ch = 'O';break;
        case 4:ch = 'I';break;
        case 5:ch = 'L';break;
        default:
               cout<<"no this shape type"<<endl;
               ch = '\0';
               break;
    }
    return ch;
}

bool Game::erasePenal()/*�������*/
{
    int i,j;
    int b[3][3] = {0};  //��ȡ��������

    m_graph->printG(CLEAR);
    memcpy(b,m_graph->getArray(),CUBE_SIZE);/*����*/
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            /*m_penal ������壬b������״*/
            m_penal[i + x][j + y] -= b[i][j];
		m_color[i][j] = CLEAR;//////////////////////////
        }
    return true;
}

bool Game::recoverPenal()//�ָ����
{
    int i,j;
    int b[3][3] = {0};  //��ȡ��������

    memcpy(b,m_graph->getArray(),CUBE_SIZE);
    for(i = x; i < x + 3; i++)
        for(j = y; j < y + 3; j++)
        {
            m_penal[i][j] += b[i-x][j-y];
		m_color[i][j] = m_graph->getColor();///////////////////////////
        }
    return true;

}

bool Game::setPenal()//�������
{
    int i,j;
    int b[3][3] = {0};  //��ȡ��������

    m_graph->getLocate(&x,&y);//��ȡ����
    memcpy(b,m_graph->getArray(),CUBE_SIZE);//��������
    /*����ȡ�����������Ƿ�����
    for(i = 0;i < 3; i++)
    {
        for(j = 0; j < 3; j++)
            cout<<b[i][j]<< " ";
        cout<<endl;
    }
    */
    for(i = x; i < x + 3; i++)
        for(j = y; j < y + 3; j++)
        {
            m_penal[i][j] += b[i-x][j-y];
            if(m_penal[i][j] > 1) //game over
            {
                cout<<"game over"<<endl;
                //�ӷ���ͳ�����а��
                system("stty icanon echo");
                exit(0);
            }
        }
    return true;
}

void Game::createCube()//������״
{
    m_graph = nextGraph;//��һ����״
	setPenal();//�������
	m_graph->printG(YELLOW);//������״

	nextGraph = new Context(getShape());//��һ����״
	nextGraph->draw();//����
	nextGraph->setLocate(1,7);//����λ��
	printNextCube(nextGraph);//��ӡ��һ����״
    /*
   for(int i = 0; i < 24; i++)
   {
        for(int j = 0; j < 17; j++)
            cout << m_penal[i][j] <<" ";
        cout << endl;
   }
   */
}

void Game::move(int dir)/*�ƶ�����*/
{

	if(GAME_RUN != mark)/*��Ϸ״̬*/
		return;
    erasePenal();/*�������*/
    switch(dir)
    {
        case DOWN:/*�����ƶ�*/
            if(false == isAttachBottom())/*û�е�����ײ�*/
            {
                m_graph->move(DOWN);//�����ƶ�
                setPenal();//�������
                m_graph->printG(YELLOW);//����ͼ��
            }
            else/*������ײ�*/
            {
                recoverPenal();/*�ָ����*/
                m_graph->printG(YELLOW);/*����ͼ��*/
                erase();/*Ĩȥ*/
                stop();/*ֹͣ��Ϸ*/
            }
            break;
        case LEFT:/*�����ƶ�*/
            if(false == isAttachLeft())/*û�е��������*/
            {
                m_graph->move(LEFT);/*������ƶ�*/
                setPenal();/*�������*/
                m_graph->printG(YELLOW);/*������״*/
            }
            else
            {
                recoverPenal();/*�ָ���״*/
                m_graph->printG(YELLOW);/*������״*/
            }
 
            break;
        case RIGHT:/*�����ƶ�*/
            if(false == isAttachRight())/*û�е������Ҳ�*/
            {
                m_graph->move(RIGHT);/*���Ҳ��ƶ�*/
                setPenal();/*�������*/
                m_graph->printG(YELLOW);/*������״*/
            }
            else
            {
                recoverPenal();/*�ָ���״*/
                m_graph->printG(YELLOW);/*������״*/
            }
            break;

        case LINE:/*�����ƶ�*/
            if (false == isAttachBottom())/*�Ƿ񵽴���ײ�*/
            {
                m_graph->move(LINE);/*�����ƶ�*/
                setPenal();/*�������*/
                m_graph->printG(YELLOW);/*������״*/
            }
            else
            {
                recoverPenal();/*�ָ���״*/
                m_graph->printG(YELLOW);/*������״*/
                erase();/*Ĩȥ*/
                stop();/*ֹͣ��Ϸ*/
            }
            break;
        default:
            break;
    }
}
void Game::roll() /*��ת��״*/
{
    //ȡ�������ֵ���ȷŵ�һ��������
    int i,j;
    int flag = 0;
    int b[3][3] = {0};  //��ȡ��������
    int temp[3][3] = {0}; /*��ʱ��������*/

    m_graph->getLocate(&x,&y);/*��ȡ��������*/
    memcpy(b,m_graph->getArray(),CUBE_SIZE);/*��������*/
    erasePenal();/*�������*/
    //��ת����
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            temp[2-j][i] = b[i][j];
        }
    //�ж���ת���Ƿ��������غ�
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if (temp[i][j] == 1 && m_penal[x + i][y + j] == 1)   
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
    }
    //������غ�����ת���飬��������ֵ
    if(flag == 0)
    {
        m_graph->roll();
    }
    setPenal();//�������
    m_graph->printG(YELLOW);//������״
}
void Game::stop()/*ֹͣ��Ϸ*/
{
    delete m_graph;
	m_graph = NULL;
    stop_flag = 1;
    createCube();
}

bool Game::isAttachBottom()/*�Ƿ񵽴�ײ�*/
{
    int i,j;
    int cube_x,cube_y;
    int b[3][3] = {0};  //��ȡ��������
    bool flag = false;

    m_graph->getLocate(&cube_x,&cube_y);
    memcpy(b,m_graph->getArray(),CUBE_SIZE);

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
           if (b[i][j] == 1 && m_penal[i + cube_x + 1][j + cube_y] == 1)
           {
                flag = true;
                break;
           }
        }
        if (flag == true)
            break;
    }
    return flag;
}

bool Game::isAttachLeft()/*�Ƿ񵽴������*/
{
    int i,j;
    int cube_x,cube_y;
    int b[3][3] = {0};  //��ȡ��������
    bool flag = false;

    m_graph->getLocate(&cube_x,&cube_y);
    memcpy(b,m_graph->getArray(),CUBE_SIZE);

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
           if (b[i][j] == 1 && m_penal[i + cube_x][j + cube_y - 1] == 1)
           {
                flag = true;
                break;
           }
        }
        if (flag == true)
            break;
    }
    return flag;

}
bool Game::isAttachRight()/*�Ƿ񵽴����Ҳ�*/
{
    int i,j;
    int cube_x,cube_y;
    int b[3][3] = {0};  //��ȡ��������
    bool flag = false;

    m_graph->getLocate(&cube_x,&cube_y);
    memcpy(b,m_graph->getArray(),CUBE_SIZE);

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
           if (b[i][j] == 1 && m_penal[i + cube_x][j + cube_y + 1] == 1)
           {
                flag = true;
                break;
           }
        }
        if (flag == true)
            break;
    }
    return flag;
}
void Game::erase() /*Ĩȥ*/
{
   int i,j;
   int flag = 0;
   static int count = 0; //�÷ּ���
   for(i = 22; i > 0; i--)
   {
        for(j = 1; j < 16; j++)
        {
            if(m_penal[i][j] == 0)
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
            //�ӷ֣�
            count++;//�����ۼ�
            s.setScore(count);//���÷���
            s.printMessage();//��ӡ��Ϣ

            //���������ͼ����������
            down(i);//����
            i++;
        }
        flag = 0;
   }
}
void Game::down(int level)//����
{
    int i,j;
    int flag = 1;

    for(i = level; i > 1; i--)
        for(j = 1; j < 16; j++)
        {
            m_penal[i][j] = m_penal[i - 1][j];
        }
    //ˢ�����
    CubePoint p;
    for(i = 1; i < 23; i++)
        for(j = 1; j < 16; j++)
        {
            if(m_penal[i][j] == 1)
            {
                p.setLocate(i,j); //����λ��
                //p.setColor(YELLOW);
		p.setColor(m_color[i][j]);//������ɫ
                p.printPoint();//��ӡ����
            }
            if(m_penal[i][j] == 0)
            {
                p.setLocate(i,j);
                p.setColor(CLEAR);
                p.printPoint();
            }
        }
}
//void listenKey(Game& g)
//{
//    
//}

int main()
{
    /*����*/
	system("clear");
    Game g;
    /*��ʼ����Ϸ*/
	g.gameInit();
    
    clock_t t_start = clock();
    while (true)
    {
        /*�Զ�����*/
        clock_t t_end = clock();
        int t_cost = ((t_end - t_start)) / CLOCKS_PER_SEC;
        if (t_cost > SPEED) {
            if (GAME_RUN == g.getMark())
            {
                t_start = t_end;
                g.move(LINE);
            }
        }
        fflush(stdin);
        /*��Ӧ����*/
        if (_kbhit()) {
            char ch;
            ch = _getch();
            switch (ch)
            {
            case 'a':
                g.move(LEFT); break; /*move�ƶ�����*/
            case 'd':
                g.move(RIGHT); break;
            case 'w':
                g.roll(); break;/*��ת����*/
            case 's':
                g.move(LINE); break;
            case ' ':
                //�ٽ�
                while (1)
                {
                    if (stop_flag == 1)/*��Ϸ�������*/
                    {
                        stop_flag = 0;
                        break;
                    }
                    g.move(DOWN);
                }
                break;

            case 'p':
                if (GAME_RUN == g.getMark())/*��ʼ����ͣ���*/
                    g.setMark(GAME_PAUSE);
                else g.setMark(GAME_RUN);
                break;

            default:
                break;
            }
        }

    }


	return 0;
}
