// cpp_mode.cpp : Defines the entry point for the console application.
//
/*
8.使用不同的声明形式创建
  两个指向const long的指针，
  一个指针指向一个long数组。
  演示能让指针增加和减少，但不能改变它所指向的值。
*/
#include "stdafx.h"

int main(int argc, char* argv[])
{
  long nl[5] = {1,2,3,4,5};
  
  const long *pL1= nl;

  long *pl3 = nl;

  long const *pL2 = nl; 

  
/*  printf("pl3第2个值是%d\r\n", (int)pl3[2]);*/
  printf("n1的地址是%p\r\n", &nl);

	printf("pL1的值%p\r\n", *pL1);
  printf("pL1的地址%p\r\n", &pL1);
  printf("pL1的地址减1%p\r\n", &pL1-1);

  printf("pL2的值%p\r\n", *pL2);
  printf("pL2的地址%p\r\n", &pL2);
  printf("pL2的地址加1%p\r\n", &pL2 + 1);

	return 0;
}

/*
n1的地址是0019FF2C

pL1的值00000001
pL1的地址0019FF28
pL1的地址减10019FF24

pL2的值00000001
pL2的地址0019FF20
pL2的地址加10019FF24
*/
