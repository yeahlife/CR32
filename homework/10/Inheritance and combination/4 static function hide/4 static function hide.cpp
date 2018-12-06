// 4 static function hide.cpp : �������̨Ӧ�ó������ڵ㡣
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
 * ʲô�����ؼ�������Ҫʲô����
 * ���ظ���ĳ�Ա���Ի���Ϊ��
 * ������Ҫ��������ͬ���͵�ͬ�����Ի���Ϊ����֮����м̳й�ϵ
 */

