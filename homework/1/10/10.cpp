// 10.cpp : Defines the entry point for the console application.
//

/*
10.创建一个const字符数组和一个指向该数组开始点的指针，
使用这个指针修改数组中的元素，看看编译器是否会报错，应当出错吗？
如果没有，为什么会认为出错？
*/

#include "stdafx.h"

int main(int argc, char* argv[])
{
  const char szBuf[10] = "hello";
  const char *p = szBuf;

	p[2] = 'r'; // error C2166: l-value specifies const object

	return 0;
}
/*
  const 是编译器语法，设置的不能修改const类型变量的值。
*/
