#ifndef CUR_H_
#define CUR_H_
#include "stdafx.h"
#include<iostream>
using namespace std;

class Cur{
public:
		void saveCur();				//������λ��
		void moveCur(const int x,const int y);	//�ƶ����λ�õ���x,y������
		void resumeCur();			//�ָ����λ��
};
#endif

