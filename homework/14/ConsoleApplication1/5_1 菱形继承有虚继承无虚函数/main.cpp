// 5_1 ���μ̳�����̳����麯��.cpp
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
    d._a = 1; // ���ʱ��ֱ�ӷ��ʾͿ����ˣ�d��������ֻ��һ��_a�ˣ������������������
    cout << d._a << endl;
    return 0;
}


