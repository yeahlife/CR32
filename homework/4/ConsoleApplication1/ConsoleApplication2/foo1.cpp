//# 1 举例说明int和int&类型不同 foo1();

#include "stdafx.h"
#include <iostream>

using namespace std;

void foo1()
{
    int n = 1;
    int& an = n;

    std::cout << n << std::endl;
    std::cout << an << std::endl;
}