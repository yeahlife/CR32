// 4 static function hide.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CTestA
{
public:
    static void fooA();
    static void fooB();
};

class CTestB:public CTestA
{
public:
    static void fooB();
};

void CTestA::fooA()
{
    cout << "CTestA fooA()" << endl;
}

void CTestA::fooB()
{
    cout << "CTestA fooB()" << endl;
}

void CTestB::fooB()
{
    cout << "CTestB fooB()" << endl;
}

int main()
{
    CTestB b;
    b.fooA();
    b.fooB();

    return 0;
}

/*
output:

CTestA fooA()
CTestB fooB()
*/

/*
 * 什么是隐藏及隐藏需要什么条件
 * 隐藏父类的成员属性或行为。
 * 隐藏需要的条件：同类型的同名属性或行为，类之间具有继承关系
 */

