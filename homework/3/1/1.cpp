// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	
  //int i = 10;
  volatile int i = 10;
  int a = i;

  printf("i = %d\r\n", a);

  //�������������þ��Ǹı��ڴ��� i ��ֵ
  //�����ֲ��ñ�����֪��
  _asm {
    mov dword ptr [ebp-4], 20h
  }

  int b = i;
  printf("i = %d\r\n", b);

	return 0;
}

