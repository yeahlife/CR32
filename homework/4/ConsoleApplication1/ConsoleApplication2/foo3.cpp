//# 3 举例说明type*和const type*类型不同 foo3();

#include "stdafx.h"
#include <iostream>

using namespace std;

void foo3()
{
    int n = 1;
    int* p1 = &n;
    const int* p2 = &n;

    //*p2 = 3;
    std::cout << n << std::endl;
    std::cout << *p1 << std::endl;
    *p1 = 3;
    std::cout << *p1 << std::endl;
    //std::cout << *p2 << std::endl;
}