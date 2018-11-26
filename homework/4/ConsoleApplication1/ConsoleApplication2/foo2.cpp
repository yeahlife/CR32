//# 2 举例说明int*和int&类型不同 foo2();

#include "stdafx.h"
#include <iostream>

using namespace std;

void foo2()
{
    int n = 1;
    int* p = &n;

    std::cout << n << std::endl;
    std::cout << &n << std::endl;
    std::cout << p << std::endl;
}