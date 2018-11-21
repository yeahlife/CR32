// 4.cpp : Defines the entry point for the console application.
//

/*
写一个函数，该函数使用指针作为参数，修改指针所指内容，然后用引用返回指针所指的内容。
*/

#include "stdafx.h"

int& foo_ref(int* p)
{
  *p = 5;
  return (*p);
}
int main(int argc, char* argv[])
{
	int n = 6;

  printf("&n is %d\r\n", foo_ref(&n));
  //&n is 5
	return 0;
}

