// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

/*
1. 通过代码，说明构造函数和析构函数的作用。
*/

#include "stdafx.h"
#include "TestA.h"


int main()
{
    // call TestA object
    CTestA test;
    
    return 0;
}

/*
output:
a:10
b:20
a:0
b:0

结论：当实例化CTestA这个类对象的时候，编译器自动调用了构造函数，程序执行完毕，编译器自动调用了析构函数
*/
