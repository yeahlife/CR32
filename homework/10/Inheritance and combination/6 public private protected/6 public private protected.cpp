// 6 public private protected.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CTestA 
{
public:
    int m_n = 1;
    void foo1() {
        cout << "CTestA foo1()" << endl;
    }

    // CTestB inherit CTestA
    int m_n_internal = 11;
    void foo1_internal() {
        cout << "CTestA foo1_internal()" << endl;
    }
protected:
    int m_n2 = 2;
    void foo2() {
        cout << "CTestA foo2()" << endl;
    }
    // CTestB inherit CTestA
    int m_n2_internal = 21;
    void foo2_internal() {
        cout << "CTestA foo2_internal()" << endl;
    }
private:
    int m_n3 = 3;
    void foo3() {
        cout << "CTestA foo3()" << endl;
    }
    // CTestB inherit CTestA
    int m_n3_internal = 31;
    void foo3_internal() {
        cout << "CTestA foo3_internal()" << endl;
    }
};

class CTestB :protected CTestA
{
public:
    int m_n = 10;
    void foo1() {
        cout << "CTestB foo1()" << endl;
    }
    void printInherit()
    {
        //可以继承 CTestA的 public protected属性
        // 在CTestB类中都是 protected权限
        this->foo1_internal();
        cout << this->m_n_internal << endl;
        this->foo2_internal();
        cout << this->m_n2_internal << endl;
    }
protected:
    int m_n2 = 20;
    void foo2() {
        cout << "CTestB foo2()" << endl;
    }
private:
    int m_n3 = 30;
    void foo3() {
        cout << "CTestB foo3()" << endl;
    }
};

class CTestC :private CTestA
{
public:
    int m_n = 100;
    void foo1() {
        cout << "CTestC foo1()" << endl;
    }

    void printInherit()
    {
        //可以继承 CTestA的 public protected属性
        // 在CTestB类中都是 private权限
        this->foo1_internal();
        cout << this->m_n_internal << endl;
        this->foo2_internal();
        cout << this->m_n2_internal << endl;
    }
protected:
    int m_n2 = 200;
    void foo2() {
        cout << "CTestC foo2()" << endl;
    }
private:
    int m_n3 = 300;
    void foo3() {
        cout << "CTestC foo3()" << endl;
    }
};

int main()
{
    // upcasting protected
    CTestA* a = new CTestA();
    CTestB* b = new CTestB();
    a = (CTestA *)b;
    a->foo1(); //CTestA foo1()
    cout << "m_n.." << a->m_n << endl;//m_n..1

    // upcasting private
    CTestC* c = new CTestC();
    a = (CTestA *)c;
    a->foo1(); //CTestA foo1()
    cout << "m_n.." << a->m_n << endl;//m_n..1
    /*
    向上派生的输出结果
    output:
    CTestA foo1()
    m_n..1
    CTestA foo1()
    m_n..1

    结论：向上派生，只能访问到基类的pulic属性的定义
    */

    /*
    类的外部访问：只能访问到pulic属性的定义
    */
    // test protected
    b->foo1();
    cout << "CTestB m_n.." << b->m_n << endl;
    b->printInherit();
  
    // test private
    c->foo1();
    cout << "CTestC m_n.." << c->m_n << endl;
    c->printInherit();

    return 0;
}

/*
output:

CTestA foo1()
m_n..1
CTestA foo1()
m_n..1
CTestB foo1()
CTestB m_n..10
CTestA foo1_internal()
11
CTestA foo2_internal()
21
CTestC foo1()
CTestC m_n..100
CTestA foo1_internal()
11
CTestA foo2_internal()
21
*/

