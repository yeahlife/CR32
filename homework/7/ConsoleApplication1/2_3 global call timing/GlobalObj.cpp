#include "stdafx.h"
#include "GlobalObj.h"
#include <iostream>

CGlobalObj::CGlobalObj()
{
    n = 10;
    std::cout << "CGlobalObj()" << std::endl
        << n << std::endl;
}


CGlobalObj::~CGlobalObj()
{
    std::cout << "~CGlobalObj()" << std::endl;
}

void CGlobalObj::printn()
{
    std::cout << "n is " << n + 10 << std::endl;
}
