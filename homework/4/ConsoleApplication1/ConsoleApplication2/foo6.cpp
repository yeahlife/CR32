//# 6 ����˵��const int&���Դ�����

#include "stdafx.h"
#include <iostream>

using namespace std;

void foo6()
{
    const int& n = 10;

    std::cout << n << std::endl;
    std::cout << &n << std::endl;
}