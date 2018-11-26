// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	
  //int i = 10;
  volatile int i = 10;
  int a = i;

  printf("i = %d\r\n", a);

  //下面汇编语句的作用就是改变内存中 i 的值
  //但是又不让编译器知道
  _asm {
    mov dword ptr [ebp-4], 20h
  }

  int b = i;
  printf("i = %d\r\n", b);

	return 0;
}

