// 2_3 global call timing.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
����˵�����캯�������������ĵ���ʱ����ջ����ȫ�ֶ��󣬶Ѷ���,������Ա����
*/

#include "stdafx.h"
#include "GlobalObj.h"


CGlobalObj globalobj;
int x = 2;

int main()
{
    int m = 100;
    globalobj.printn();

    return 0;
}

/*
ȫ�ֶ��󣬾�̬����󴴽�

�ڽ���main����֮ǰ���Ѿ������������
*/

/*
output:
CGlobalObj()
10
n is 20
~CGlobalObj()
*/


