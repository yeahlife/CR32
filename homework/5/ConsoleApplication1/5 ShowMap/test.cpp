#include "stdafx.h"
#include "test.h"
#include <iostream>

using namespace std;

int tagTest::SetN1(int n)
{
    this->n1 = n;
    return 0;
}

int tagTest::GetN1()
{
    return (this->n1);
}

// 打印数据成员名字和它们的地址
void tagTest::ShowMap()
{
    std::cout << "public："<< std::endl;
    std::cout << "tagTest.n1 address is：" << (int *)&this->n1 << std::endl;
    std::cout << "tagTest.n1 value is：" << this->n1 << std::endl;
    std::cout << "protected：" << std::endl;
    std::cout << "tagTest.n2 address is：" << (int *)&this->n2 << std::endl;
    std::cout << "private：" << std::endl;
    std::cout << "tagTest.n3 address is：" << (int *)&this->n3 << std::endl;
}

int tagTest::SetN2(int n)
{
    this->n2 = n;
    return 0;
}

int tagTest::GetN2()
{
    return (this->n2);
}

int tagTest::SetN3(int n)
{
    this->n3 = n;
    return 0;
}

int tagTest::GetN3()
{
    return (this->n3);
}