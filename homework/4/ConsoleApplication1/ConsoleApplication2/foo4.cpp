//# 4 举例说明typedef int MYINT类型

#include "stdafx.h"
#include <iostream>

using namespace std;

//typedef user-defined type int to MYINT
typedef int MYINT;

void foo4()
{
    int n = 1;
    MYINT m = 2;

    std::cout << n << std::endl;
    std::cout << m << std::endl;
}