// type conversion downcasting.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//����
class CTestA
{
public:
    CTestA(int a1, int a2);
    void display();
protected:
    int m_a1;
    int m_a2;
};
CTestA::CTestA(int a1, int a2):m_a1(a1), m_a2(a2){}
void CTestA::display(){ cout << m_a1 << ", " << m_a2 << endl; }

//������
class CTestB:public CTestA
{
public:
    CTestB(int a1, int a2, int b);
    void display();
private:
    int m_b;
};
CTestB::CTestB(int a1, int a2, int b):CTestA(a1, a2), m_b(b){}
void CTestB::display() { cout << m_a1<<", " << m_a2 << ", " << m_b << endl; }


int main()
{
    CTestB *ptrB = (CTestB*)new CTestA(1,2);
    ptrB->display(); //display ����B�ĳ�Ա����������A�ĳ�Ա����

    return 0;
}
/*
output:
1, 2, -33686019
*/

