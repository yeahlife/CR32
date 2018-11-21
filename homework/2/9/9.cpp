// 9.cpp : Defines the entry point for the console application.
//
/*
 9.举例说明何时使用函数默认参及使用时需要注意的什么。
*/

#include "stdafx.h"

void Func(int i = 1, float f = 2.0f, double d = 3.0)
{
  printf("%d %.1f %.1f\r\n", i, f, d);
}

int main(int argc, char* argv[])
{
	Func();// 1 2.0 3.0
  Func(2);// 2 2.0 3.0
  Func(2, 5.0f);//2 5.0 3.0
  Func(2, 5.0f, 6.0f);//2 5.0 6.0

	return 0;
}
/*
如果某个参数是默认参数，那么它后面的参数必须都是默认参数
默认参数可以放在函数声明或者定义中，但只能放在二者之一
函数重载时谨慎使用默认参数值
*/

