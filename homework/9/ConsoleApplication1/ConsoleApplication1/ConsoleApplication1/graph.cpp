#include "stdafx.h"
#include "graph.h"
void Gbase::printG(int color) //��ӡ��ɫ
{
    int i,j;
    CubePoint p; /*��״����*/
    /*
     * 3x3��ʾ����״
     * ÿ���ƶ�3��
     */
    for(i = x; i < x+3; i++)
        for(j = y; j < y+3; j++)
        {
            if(a[i - x][j - y] == 1) /*? a[i-x][j-y]�����Ҫ����ʲô*/
            {
                p.setLocate(i,j);
                p.setColor(color);
                p.printPoint();
            }
        }
}
int Gbase::move(int dir)//�����ƶ�
{
	switch(dir)
	{
		case DOWN:x++;break;
		case LEFT:y--;break;
		case RIGHT:y++;break;
        case LINE:x++; break;
		default:
				break;
	}
    return 0;
}

int Gbase::roll()//��ת����
{
    int i,j;
    int b[3][3];
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            b[2-j][i] = a[i][j];
        }
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            a[i][j] = b[i][j];
        }
    return 0;
}


