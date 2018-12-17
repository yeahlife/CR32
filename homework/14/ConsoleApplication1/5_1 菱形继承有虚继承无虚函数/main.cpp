// 5_1 菱形继承有虚继承无虚函数.cpp
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A {
public:
    A() {
        _a = 1;
    };
public:
    int _a;
};

class B : virtual public A {
public:
    B() {
        _b = 2;
    }
public:
    int _b;
};

class C : virtual public A {
public:
    C() {
        _c = 3;
    }
public:
    int _c;
};

class D :public B, public C {
public:
    D() {
        _d = 4;
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
    d._a = 1; // 这个时候直接访问就可以了，d对象里面只有一个_a了，解决了数据冗余问题
    cout << d._a << endl;
    return 0;
}


