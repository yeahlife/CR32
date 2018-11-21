// 9.cpp : Defines the entry point for the console application.
//
/*
9.写一个指向double类型的const指针，让它指向double数组。
显示能改变指针指向的内容，但不能增加或减小指针。
*/

#include "stdafx.h"

int main(int argc, char* argv[])
{
  int i = 0;
  double dbl[5] = {1.0, 2.0, 3.0, 4.0, 5.0};

  double *const pDbl = dbl; // 右定向，指针不可改变

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

