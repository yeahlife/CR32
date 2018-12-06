// 2 A B C.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class A
{
    A()
    {
        printf("class A");
    }
};

class B {
    B()
    {
        printf("class B");
    }
};

class C:public A
{
    B b;
};

int main()
{
    //C c; //提示说C没有默认的构造函数
    return 0;
}

