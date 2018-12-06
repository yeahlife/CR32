#ifndef CUBEPOINT_H_
#define CUBEPOINT_H_
#include "stdafx.h"
#include<iostream>
#include "cur.h"
using namespace std;
enum color{
	CLEAR = 0,
	BLACK = 30,
	RED, //31
	GREEN,//32
	YELLOW,//33
	BLUE,//34
	PURPLE,//35
	DEEP_GREEN,//36
	WHITE//37
};

/*
 * 显示面板我们看作是很多方形的小点组成
 * 每个点显然有个坐标值
 * 每个点有一个颜色
 * 这种思维来设计更为合理
 */
class CubePoint{
protected:
	int color;
	int x;
	int y; //每个方格点有颜色属性，坐标属性
public:
	CubePoint()
	{
		color = CLEAR;
		x = 0;
		y = 0;
	}
	CubePoint(int a,int b,int c)
	{
		color = a;
		x = b;
		y = c;
	}
	void setLocate(const int x,const int y){this->x = x;this->y = y;}/*设置位置*/
	void setColor(const int color){this->color = color;}/*设置颜色*/
	
	int getColor(){return color;}
	void getLocate(int&x,int &y){x = this->x;y = this->y;}
	//打印点的方法
	void printPoint();
};
#endif

