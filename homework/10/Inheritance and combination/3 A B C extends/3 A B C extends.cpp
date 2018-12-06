// 3 A B C extends.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CTop
{
private:
    int m_a;

public:
    CTop(int a);
    ~CTop();
};

class CMiddle:public CTop
{
private:
    int m_b;

public:
    CMiddle(int a, int b);
    ~CMiddle();
};

class CBottom:public CMiddle
{
private:
    int m_c;
    
public:
    CBottom(int a, int b, int c);
    ~CBottom();
};

CTop::CTop(int a = 0)
{
    this->m_a = a;
    cout << "a.." << m_a << endl;
    cout << "CTop constructed\r\n";
}

CTop::~CTop()
{
    this->m_a = 0;
    cout << "a.." << m_a << endl;
    cout << "~CTop deconstructed\r\n";
}

CMiddle::CMiddle(int a = 0, int b = 0) :CTop(a) //��ʼ����Ա�б�ִ��CTop���еĹ��캯��
{
    this->m_b = b;
    cout << "b.." << m_b << endl;
    cout << "CMiddle constructed\r\n";
}

CMiddle::~CMiddle()
{
    this->m_b = 0;
    cout << "b.." << m_b << endl;
    cout << "~CMiddle constructed\r\n";
}

CBottom::CBottom(int a, int b, int c):CMiddle(a,b)//��ʼ����Ա�б�ִ��CMiddle���еĹ��캯��
{
    this->m_c = c;
    cout << "c.." << m_c << endl;
    cout << "CBottom constructed\r\n";
}

CBottom::~CBottom()
{
    this->m_c = 0;
    cout << "c.." << m_c << endl;
    cout << "~CBottom constructed\r\n";
}


int main()
{
    CBottom bottom(1, 2, 3);

    return 0;
}
/*
output:

a..1
CTop constructed
b..2
CMiddle constructed
c..3
CBottom constructed
c..0
~CBottom constructed
b..0
~CMiddle constructed
a..0
~CTop deconstructed
*/

/*
���������ʱ��Ӧ�ȵ����乹�캯����
�������������г�Ա������Ҫ��ִ�г�Ա�����Լ�������Ĺ��캯����
��ȫ����Ա����ִ����������Ĺ��캯������ִ�е�ǰ��Ĺ��캯����

����˳��
���캯�� 
CTop -> CMiddle -> CBottom

��������
CBottom -> CMiddle -> CTop
*/