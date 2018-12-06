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
 * ��ʾ������ǿ����Ǻܶ෽�ε�С�����
 * ÿ������Ȼ�и�����ֵ
 * ÿ������һ����ɫ
 * ����˼ά����Ƹ�Ϊ����
 */
class CubePoint{
protected:
	int color;
	int x;
	int y; //ÿ�����������ɫ���ԣ���������
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
	void setLocate(const int x,const int y){this->x = x;this->y = y;}/*����λ��*/
	void setColor(const int color){this->color = color;}/*������ɫ*/
	
	int getColor(){return color;}
	void getLocate(int&x,int &y){x = this->x;y = this->y;}
	//��ӡ��ķ���
	void printPoint();
};
#endif

