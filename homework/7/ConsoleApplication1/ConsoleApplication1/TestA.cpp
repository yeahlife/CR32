#include "stdafx.h"
#include "TestA.h"
#include <iostream>

// construct function
CTestA::CTestA()
{
    a = 10;
    b = 20;
    std::cout << "a:" << a << std::endl
                << "b:" << b << std::endl;
}

// destory function
CTestA::~CTestA()
{
    a = 0;
    b = 0;
    std::cout << "a:" << a << std::endl
                << "b:" << b << std::endl;
}
