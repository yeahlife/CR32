// c_mode.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

int main(int argc, char* argv[])
{
  const int n1 = 1;
  const int n2 = 2;
  const int n3 = 3;
  char szBuf[n1+n2+n3] = {0};
  
  return 0;
}
/*
error C2057: expected constant expression
error C2466: cannot allocate an array of constant size 0
C语法不支持变量声明数组的形式。它期望的是常量来声明。
Cpp语法支持。
*/

