// 9.cpp : Defines the entry point for the console application.
//
/*
9.дһ��ָ��double���͵�constָ�룬����ָ��double���顣
��ʾ�ܸı�ָ��ָ������ݣ����������ӻ��Сָ�롣
*/

#include "stdafx.h"

int main(int argc, char* argv[])
{
  int i = 0;
  double dbl[5] = {1.0, 2.0, 3.0, 4.0, 5.0};

  double *const pDbl = dbl; // �Ҷ���ָ�벻�ɸı�

  pDbl[2] = 3.5;

  for(i=0; i<5; i++)
  {
    	printf("%.2f\t", pDbl[i]);
  }

	return 0;
}
/*
output:
1.00    2.00    3.50    4.00    5.00
*/

