//# 1 ����˵��int��int&���Ͳ�ͬ foo1();

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