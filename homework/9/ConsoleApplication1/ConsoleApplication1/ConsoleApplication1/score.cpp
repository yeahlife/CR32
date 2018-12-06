#include "stdafx.h"
#include "score.h"
#include "cur.h"
#include "cubePoint.h"

void Score::printMessage()//打印信息
{
   Cur c;      //坐标类
   CubePoint p;//方块类

   p.setLocate(2,19);//设置位置
   p.setColor(WHITE);//设置颜色
   p.printPoint();//? 打印坐标点
   
   c.saveCur();//保存坐标点
   c.moveCur(2,21);//移动坐标点
   cout<<"player: "<<player;//打印玩家信息
   c.resumeCur();//恢复坐标

   p.setLocate(4,19);//设置位置
   p.setColor(GREEN);//设置颜色
   p.printPoint();//? 打印坐标点

   c.saveCur();//保存坐标点
   c.moveCur(4,21);//移动坐标点
   cout<<"score : "<<score;//打印分数信息
   c.resumeCur();//恢复坐标

}
