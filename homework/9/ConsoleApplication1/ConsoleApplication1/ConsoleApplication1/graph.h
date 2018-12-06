#include "stdafx.h"
#include <iostream>
using namespace std;
#include <stdio.h>
#include "cubePoint.h"
#include <stdlib.h>
#define DOWN 0
#define LEFT 1
#define RIGHT 2
#define LINE 3


class Gbase{
protected:
	int x;
	int y;	//a[0][0]��λ��
	int a[3][3];
public:
	Gbase(){
		int i,j;
		x = 0;
		y = 0;
        /*��ʼ��������״*/
		for(j = 0; j < 3; j++)
		for(i = 0; i < 3; i++)
		a[i][j] = 0;
	}
	int move(int dir);
	virtual int roll();
	virtual void draw(){}
	void setLocate(int a,int b){x = a;y = b;}/*���÷���λ��*/
    void getLocate(int* a,int* b){*a = x;*b = y;}/*��ȡ����λ��*/
    void printG(int color); //��ӡ��ɫ
    void* getArray(){return (void*)a;}//��ȡ�����׵�ַ
};

class Zgraph : public Gbase{ //��״ Z
public:
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 1;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;
	}
};
class Tgraph : public Gbase{//��״ T
public:
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 1;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;
	}
};
class Ograph : public Gbase{// ��״ O
public:
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 0;
		a[1][0] = 1;
		a[1][1] = 1;
		a[1][2] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;
	}
    virtual int roll() { return 0; }
};
class Igraph : public Gbase{//��״ I
public:
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 0;
	}
};
class Lgraph : public Gbase{//��״ L
public:
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 1;
	}
};

class Context //�龳
{
private:
	Gbase* gbase;
	color clr;

public:
    ~Context()
    {
        delete gbase;
    }
	Context(char cType) //��ȡ��״����ɫ
	{
		switch(cType)
		{
			case 'Z':
				gbase = new Zgraph();clr = YELLOW;///
				break;
			case 'T':
				gbase = new Tgraph();clr = GREEN;///
				break;
			case 'O':
				gbase = new Ograph();clr = PURPLE;///
				break;
			case 'I':
				gbase = new Igraph();clr = DEEP_GREEN;///
				break;
			case 'L':
				gbase = new Lgraph();clr = WHITE;///
				break;
			default:
				printf("no %c type\n",cType);
				break;
		}
	}
	int move(int dir){return gbase->move(dir);}
	int roll(){return gbase->roll();}
	void draw(){gbase->draw();}

	void setLocate(int a,int b){gbase->setLocate(a,b);}
    void getLocate(int *a,int* b){gbase->getLocate(a,b);}
    void* getArray() { return gbase->getArray();}

//    void printG(int color){gbase->printG(color);}
    void printG(int color){
	if(color == CLEAR)
		gbase->printG(CLEAR);
	else gbase->printG(clr);
	}

void setColor(color clr)
{
	this->clr = clr;
}
color getColor()
{
	return clr;
}

};

