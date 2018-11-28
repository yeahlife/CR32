// 2_3 global call timing.cpp : 定义控制台应用程序的入口点。
//
/*
举例说明构造函数和析构函数的调用时机（栈对象，全局对象，堆对象,类对象成员）。
*/

#include "stdafx.h"
#include "GlobalObj.h"


CGlobalObj globalobj;
int x = 2;

int main()
{
    int m = 100;
    globalobj.printn();

    return 0;
}

/*
全局对象，静态类对象创建

在进入main函数之前就已经创建好类对象
*/

/*
output:
CGlobalObj()
10
n is 20
~CGlobalObj()
*/


