// 2 A B C.cpp : �������̨Ӧ�ó������ڵ㡣
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
    //C c; //��ʾ˵Cû��Ĭ�ϵĹ��캯��
    return 0;
}

