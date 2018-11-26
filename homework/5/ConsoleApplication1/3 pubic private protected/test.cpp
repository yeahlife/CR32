#include "stdafx.h"
#include "test.h"

// 函数的定义，需要加上结构体名作用域
// public
int tagTest::SetN1(int n1)
{
    this->n1 = n1;

    return 0;
}

int tagTest::GetN1()
{
    return (this->n1);
}

// protected
int tagTest::SetN2(int n2)
{
    this->n2 = n2;

    return 0;
}

int tagTest::GetN2()
{
    return (this->n2);
}

// private
int tagTest::SetN3(int n3)
{
    this->n3 = n3;

    return 0;
}

int tagTest::GetN3()
{
    return (this->n3);
}