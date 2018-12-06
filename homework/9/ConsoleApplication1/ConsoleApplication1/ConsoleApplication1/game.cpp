#include "stdafx.h"
#include "game.h"
#include "rand.h"
#include <cstring>
#include<cstdio>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#define SPEED 1 /*自动下落间隔 秒*/
#define PENAL_SIZE (17*24*sizeof(int)) /*整个面板大小*/
#define CUBE_SIZE (3*3*sizeof(int)) /*方块形状大小*/

int num = 0;

static int stop_flag;
//为了只调用srand函数一次，这样时间相近产生的随机数就不会重复
static Rand r;

/////////////////////////////////////////////
void Game::printNextCube(Context* graph) /*下一个形状*/
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

    int a[3][3] = {0};  //获取方块数组
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

void Game::printHelep() /*右侧提示信息*/
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

void Game::gameInit()/*game 初始化*/
{
    /*打印说明*/
	printHelep();
    /*预测下一个方块形状*/
	nextGraph = new Context(getShape());
	nextGraph->draw();/*?这里用到了虚函数 virtual*/
	nextGraph->setLocate(1,7);
    /*创建形状*/
	createCube();
}

MARK Game::getMark() /*获取游戏状态*/
{
	return mark;
}
void Game::setMark( MARK mark )/*设置游戏状态*/
{
	this->mark = mark;
}

Game::~Game()/*game 析构*/
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

Game::Game()/*game 构造*/
{
    m_graph = NULL;
    x = 1;
    y = 7;
    CubePoint p;
    int i;
    s.printMessage();//打印消息

	mark = GAME_RUN;////////////////////////////////////////////////

    memset((void*)m_penal,0,PENAL_SIZE); //面板初始化
	memset((void*)m_color,0,PENAL_SIZE); //color初始化
   for(i = 0; i < 24; i++)//绘制边框
   {
        p.setLocate(i,0);
        p.setColor(BLUE);
        p.printPoint();
        p.setLocate(i,16);
        p.setColor(BLUE);
        p.printPoint();
        m_penal[i][0] = 1; //墙
        m_penal[i][16] = 1;//墙
   }
   for(i = 0; i < 17; i++) //绘制边框
   {
        p.setLocate(23,i);
        p.setColor(BLUE);
        p.printPoint();
        p.setLocate(0,i);
        p.setColor(RED);
        p.printPoint();
        m_penal[23][i] = 1;//墙
        m_penal[0][i] = 1; //墙
   }
   /*测试面板值是否正常
   for(i = 0; i < 24; i++)
   {
        for(int j = 0; j < 17; j++)
            cout << m_penal[i][j] <<" ";
        cout << endl;
   }
   */
   fflush(stdout);
}

char Game::getShape()/*获得方块形状*/
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

bool Game::erasePenal()/*擦除面板*/
{
    int i,j;
    int b[3][3] = {0};  //获取方块数组

    m_graph->printG(CLEAR);
    memcpy(b,m_graph->getArray(),CUBE_SIZE);/*拷贝*/
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            /*m_penal 整个面板，b方块形状*/
            m_penal[i + x][j + y] -= b[i][j];
		m_color[i][j] = CLEAR;//////////////////////////
        }
    return true;
}

bool Game::recoverPenal()//恢复面板
{
    int i,j;
    int b[3][3] = {0};  //获取方块数组

    memcpy(b,m_graph->getArray(),CUBE_SIZE);
    for(i = x; i < x + 3; i++)
        for(j = y; j < y + 3; j++)
        {
            m_penal[i][j] += b[i-x][j-y];
		m_color[i][j] = m_graph->getColor();///////////////////////////
        }
    return true;

}

bool Game::setPenal()//设置面板
{
    int i,j;
    int b[3][3] = {0};  //获取方块数组

    m_graph->getLocate(&x,&y);//获取坐标
    memcpy(b,m_graph->getArray(),CUBE_SIZE);//拷贝方块
    /*测试取到方块数组是否正常
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
                //加分数统计排行榜等
                system("stty icanon echo");
                exit(0);
            }
        }
    return true;
}

void Game::createCube()//创建形状
{
    m_graph = nextGraph;//下一个形状
	setPenal();//设置面板
	m_graph->printG(YELLOW);//绘制形状

	nextGraph = new Context(getShape());//下一个形状
	nextGraph->draw();//绘制
	nextGraph->setLocate(1,7);//设置位置
	printNextCube(nextGraph);//打印下一个形状
    /*
   for(int i = 0; i < 24; i++)
   {
        for(int j = 0; j < 17; j++)
            cout << m_penal[i][j] <<" ";
        cout << endl;
   }
   */
}

void Game::move(int dir)/*移动方块*/
{

	if(GAME_RUN != mark)/*游戏状态*/
		return;
    erasePenal();/*擦除面板*/
    switch(dir)
    {
        case DOWN:/*向下移动*/
            if(false == isAttachBottom())/*没有到达最底部*/
            {
                m_graph->move(DOWN);//向下移动
                setPenal();//重置面板
                m_graph->printG(YELLOW);//绘制图案
            }
            else/*到达最底部*/
            {
                recoverPenal();/*恢复面板*/
                m_graph->printG(YELLOW);/*绘制图案*/
                erase();/*抹去*/
                stop();/*停止游戏*/
            }
            break;
        case LEFT:/*向左移动*/
            if(false == isAttachLeft())/*没有到达最左侧*/
            {
                m_graph->move(LEFT);/*向左侧移动*/
                setPenal();/*设置面板*/
                m_graph->printG(YELLOW);/*绘制形状*/
            }
            else
            {
                recoverPenal();/*恢复形状*/
                m_graph->printG(YELLOW);/*绘制形状*/
            }
 
            break;
        case RIGHT:/*向右移动*/
            if(false == isAttachRight())/*没有到达最右侧*/
            {
                m_graph->move(RIGHT);/*向右侧移动*/
                setPenal();/*设置面板*/
                m_graph->printG(YELLOW);/*绘制形状*/
            }
            else
            {
                recoverPenal();/*恢复形状*/
                m_graph->printG(YELLOW);/*绘制形状*/
            }
            break;

        case LINE:/*按行移动*/
            if (false == isAttachBottom())/*是否到达最底部*/
            {
                m_graph->move(LINE);/*向下移动*/
                setPenal();/*设置面板*/
                m_graph->printG(YELLOW);/*绘制形状*/
            }
            else
            {
                recoverPenal();/*恢复形状*/
                m_graph->printG(YELLOW);/*绘制形状*/
                erase();/*抹去*/
                stop();/*停止游戏*/
            }
            break;
        default:
            break;
    }
}
void Game::roll() /*旋转形状*/
{
    //取出方块的值，先放到一个数组中
    int i,j;
    int flag = 0;
    int b[3][3] = {0};  //获取方块数组
    int temp[3][3] = {0}; /*临时方块数组*/

    m_graph->getLocate(&x,&y);/*获取方块坐标*/
    memcpy(b,m_graph->getArray(),CUBE_SIZE);/*拷贝方块*/
    erasePenal();/*重置面板*/
    //旋转数组
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            temp[2-j][i] = b[i][j];
        }
    //判断旋转后是否会与面板重合
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
    //如果不重合则旋转方块，设置面板的值
    if(flag == 0)
    {
        m_graph->roll();
    }
    setPenal();//设置面板
    m_graph->printG(YELLOW);//绘制形状
}
void Game::stop()/*停止游戏*/
{
    delete m_graph;
	m_graph = NULL;
    stop_flag = 1;
    createCube();
}

bool Game::isAttachBottom()/*是否到达底部*/
{
    int i,j;
    int cube_x,cube_y;
    int b[3][3] = {0};  //获取方块数组
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

bool Game::isAttachLeft()/*是否到达最左侧*/
{
    int i,j;
    int cube_x,cube_y;
    int b[3][3] = {0};  //获取方块数组
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
bool Game::isAttachRight()/*是否到达最右侧*/
{
    int i,j;
    int cube_x,cube_y;
    int b[3][3] = {0};  //获取方块数组
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
void Game::erase() /*抹去*/
{
   int i,j;
   int flag = 0;
   static int count = 0; //得分计数
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
            //加分！
            count++;//分数累加
            s.setScore(count);//设置分数
            s.printMessage();//打印信息

            //该行上面的图形整体坐落
            down(i);//消行
            i++;
        }
        flag = 0;
   }
}
void Game::down(int level)//消行
{
    int i,j;
    int flag = 1;

    for(i = level; i > 1; i--)
        for(j = 1; j < 16; j++)
        {
            m_penal[i][j] = m_penal[i - 1][j];
        }
    //刷新面板
    CubePoint p;
    for(i = 1; i < 23; i++)
        for(j = 1; j < 16; j++)
        {
            if(m_penal[i][j] == 1)
            {
                p.setLocate(i,j); //设置位置
                //p.setColor(YELLOW);
		p.setColor(m_color[i][j]);//设置颜色
                p.printPoint();//打印坐标
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
    /*清屏*/
	system("clear");
    Game g;
    /*初始化游戏*/
	g.gameInit();
    
    clock_t t_start = clock();
    while (true)
    {
        /*自动下落*/
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
        /*响应键盘*/
        if (_kbhit()) {
            char ch;
            ch = _getch();
            switch (ch)
            {
            case 'a':
                g.move(LEFT); break; /*move移动方块*/
            case 'd':
                g.move(RIGHT); break;
            case 'w':
                g.roll(); break;/*旋转方块*/
            case 's':
                g.move(LINE); break;
            case ' ':
                //速降
                while (1)
                {
                    if (stop_flag == 1)/*游戏结束标记*/
                    {
                        stop_flag = 0;
                        break;
                    }
                    g.move(DOWN);
                }
                break;

            case 'p':
                if (GAME_RUN == g.getMark())/*开始或暂停标记*/
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
