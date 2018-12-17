// 5_2 菱形继承无虚继承有虚函数.cpp
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A {
public:
    A() {
        _a = 1;
    };

    virtual void funA() {
        printf("A::funA()\r\n");
    }

public:
    int _a;
};

class B : public A {
public:
    B() {
        _b = 2;
    }

    virtual void funB() {
        printf("B::funB()\r\n");
    }
public:
    int _b;
};

class C : public A {
public:
    C() {
        _c = 3;
    }

    virtual void funC() {
        printf("C::funC()\r\n");
    }
public:
    int _c;
};

class D :public B, public C {
public:
    D() {
        _d = 4;
    }

    virtual void funA() {
        printf("D::funA()\r\n");
    }

    virtual void funB() {
        printf("D::funB()\r\n");
    }

    virtual void funC() {
        printf("D::funC()\r\n");
    }

public:
    int _d;
};

int main()
{
    A a;
    B b;
    C c;
    D d;

    d.B::_a = 10; // 通过指定是哪个类中的_a来消除二义性的目的
    cout << d.B::_a << endl;

    // 函数调用
    // 将派生类对象赋值给基类对象
    // a->b a->c
    a = b;
    a.funA();  // A::funA()
    a = c;
    a.funA();  // A::funA()
    // b->d c->d
    b = d;
    b.funA();  // A::funA()
    b.funB();  // B::funB()
    c = d;
    c.funA();  // A::funA()
    c.funC();  // C::funC()
    printf("\r\n");

    // 将派生类指针赋值给基类指针
    // a->b a->c
    A* pa = &b;
    pa->funA();  // A::funA()
    A* pa2 = &c;
    pa2->funA(); // A::funA()
    // b->d c->d
    B* pb = &d;
    pb->funA();  // D::funA()
    pb->funB();  // D::funB()
    B* pb2 = &d;
    pb2->funA(); // D::funA()
    pb2->funB(); // D::funB()
    printf("\r\n");

    // 将派生类引用赋值给基类引用
    // a->b a->c
    A &ra = b;
    ra.funA();  // A::funA()
    A &ra2 = c;
    ra2.funA(); // A::funA()
    // b->d c->d
    B &rb = d;
    rb.funA();  // D::funA()
    rb.funB();  // D::funB()
    B &rb2 = d;
    rb2.funA(); // D::funA()
    rb2.funB(); // D::funB()

    return 0;
}
/*
output:

10
A::funA()
A::funA()
A::funA()
B::funB()
A::funA()
C::funC()

A::funA()
A::funA()
D::funA()
D::funB()
D::funA()
D::funB()

A::funA()
A::funA()
D::funA()
D::funB()
D::funA()
D::funB()
*/



