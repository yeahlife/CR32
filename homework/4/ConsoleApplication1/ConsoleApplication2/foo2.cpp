//# 2 ����˵��int*��int&���Ͳ�ͬ foo2();

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