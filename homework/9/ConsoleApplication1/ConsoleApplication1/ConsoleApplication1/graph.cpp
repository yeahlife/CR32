#include "stdafx.h"
#include "graph.h"
void Gbase::printG(int color) //打印颜色
{
    int i,j;
    CubePoint p; /*形状对象*/
    /*
     * 3x3表示的形状
     * 每次移动3格
     */
    for(i = x; i < x+3; i++)
        for(j = y; j < y+3; j++)
        {
            if(a[i - x][j - y] == 1) /*? a[i-x][j-y]这个是要计算什么*/
            {
                p.setLocate(i,j);
                p.setColor(color);
                p.printPoint();
            }
        }
}
int Gbase::move(int dir)//方块移动
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

int Gbase::roll()//旋转方块
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


