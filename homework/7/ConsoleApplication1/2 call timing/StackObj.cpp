#include "stdafx.h"
#include "StackObj.h"
#include <iostream>

CStackObj::CStackObj()
{
    a = 10;
    b = 20;
    std::cout << "a:" << a << std::endl
        << "b:" << b << std::endl;
}


//CStackObj::~CStackObj()
//{
//    a = 0;
//    b = 0;
//    std::cout << "a:" << a << std::endl
//        << "b:" << b << std::endl;
//}
