// 5. ���μ̳�.cpp
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

class B :public A {
public:
    B() {
        _b = 2;
    }
public:
    int _b;
};

class C :public A {
public:
    C() {
        _c = 3;
    }
public:
    int _c;
};

class D :public B, public C{
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
    d.B::_a = 1; // ͨ��ָ�����ĸ����е�_a�����������Ե�Ŀ��
    d.C::_a = 2;
    cout << d.B::_a<<" " << d.C::_a << endl;
    return 0;
}

