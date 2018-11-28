#include "stdafx.h"
#include "MemberObj.h"
#include <iostream>

//无参构造函数
CMemberObj::CMemberObj()
{
    std::cout << "CMemberObj()" << std::endl;
}
//有参构造函数
CMemberObj::CMemberObj(int n)
{
    std::cout << "CMemberObj(int n)" << n << std::endl;
}


CMemberObj::~CMemberObj()
{
    std::cout << "~CMemberObj()" << std::endl;
}
