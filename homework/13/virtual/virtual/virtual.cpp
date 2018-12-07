/*
运行并调试 下面的代码。
试预测并说明程序执行结果,
并以此为基础总结覆盖、隐藏、重载的区别（触发条件的区别、实现原理的区别）

观察以上类声明及实现，试预测以下main中的执行结果。
注意两点：
1. 调用的方法是哪个
2. 调用造成的原因，是重载、覆盖、隐藏中的哪一种？
*/

#include "StdAfx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Handle1(float x)
    {
        cout << "Base::Handle1(float) " << x << endl;
    }
    void Handle2(float x)
    {
        cout << "Base::Handle2(float) " << x << endl;
    }
    void Handle3(float x)
    {
        cout << "Base::Handle3(float) " << x << endl;
    }
};

class Derived : public Base
{
public:
    virtual void Handle1(float x)
    {
        cout << "Derived::Handle1(float) " << x << endl;
    }
    void Handle2(int x)
    {
        cout << "Derived::Handle2(int) " << x << endl;
    }
    void Handle3(float x)
    {
        cout << "Derived::Handle3(float) " << x << endl;
    }
    void Handle3(double x)
    {
        cout << "Derived::Handle3(double) " << x << endl;
    }
};


void main(void)
{
    Derived DervObj;
    Base *pBase = &DervObj;
    Derived *pDerv = &DervObj;

    pBase->Handle1(3.14f); //Handle1是虚函数，pBase是指针调用，函数覆盖规则，Derived::Handle1(float) 3.14
    pDerv->Handle1(3.14f); //Handle1是虚函数，pDerv是指针调用，函数覆盖规则，Derived::Handle1(float) 3.14
    cout << endl;

    pBase->Handle2(3.14f); //Handle2是普通函数，直接调用，函数隐藏，Base::Handle2(float) 3.14
    pDerv->Handle2(3.14f); //Handle2是普通函数，直接调用，函数隐藏，Derived::Handle2(int) 3
    cout << endl;

    pBase->Handle3(3.14f); //Handle3是普通函数，直接调用，函数隐藏，函数重载，Base::Handle3(float) 3 
    pDerv->Handle3(3.14f); //Handle3是普通函数，直接调用，函数隐藏，函数重载，Derived::Handle3(float) 3.14
    pDerv->Handle3(3.14);  //Handle3是普通函数，直接调用，函数隐藏，函数重载，Derived::Handle3(double) 3.14
    cout << endl;

    //pDerv->Handle3(3);
}