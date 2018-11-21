// 11.cpp : Defines the entry point for the console application.
//

/*
11. 创建一个函数，它带有一个const值传递的参数，然后在函数体中试图改变该参数。
*/

#include "stdafx.h"

//void char_const_test(const char *szBuf)
//error C2440: 'initializing' : cannot convert from 'const char *' to 'char *'

void char_const_test(char *szBuf)
{
  char *psz = szBuf;

  psz[2] = 'r';
}

int main(int argc, char* argv[])
{
	char szBuf[10] = "hello";

  char_const_test(szBuf);

  printf("szBuf %s\r\n", szBuf);

	return 0;
}
/*
output:
szBuf herlo
*/
