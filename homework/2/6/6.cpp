// 6.cpp : Defines the entry point for the console application.
//

/*
创建一个函数，使其用char&作参数并修改该参数。
在main()函数里，打印一个char变量，使用这个变量做参数，调用我们设计的函数。
然后，再次打印此变量以证明它已被改变。请问这影响了程序的可读性吗？
*/


#include "stdafx.h"

void cchange(char& ch)
{
  ch = 'b';
  
  return;
}


int main(int argc, char* argv[])
{
  char cTest = 'a';
  
  printf("c %c\r\n", cTest);
  cchange(cTest);
  printf("c %c\r\n", cTest);
	printf("Hello World!\n");
	return 0;
}

/*
output:
c a
c b
*/

