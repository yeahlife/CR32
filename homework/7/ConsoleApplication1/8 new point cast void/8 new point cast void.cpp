// 8 new point cast void.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CTest
{
public:
    CTest();
    ~CTest();

private:

};

CTest::CTest()
{
    std::cout << "CTest()" << std::endl;
}

CTest::~CTest()
{
    std::cout << "~CTest()" << std::endl;
}

int main()
{
    void* ptr = new CTest;
    delete ptr;

    return 0;
}

/*
new Class CTest �����Ķ���ָ��������CTest���͵�
���ת����void *���ٵ���delete�ͷ��ڴ棬�ᱨ��
����ִ����������

ɾ�����ָ��������������ת��Ϊvoid�Ͳ���������

*/

