#include "stdafx.h"
#include "MemberObj.h"
#include <iostream>

//�޲ι��캯��
CMemberObj::CMemberObj()
{
    std::cout << "CMemberObj()" << std::endl;
}
//�вι��캯��
CMemberObj::CMemberObj(int n)
{
    std::cout << "CMemberObj(int n)" << n << std::endl;
}


CMemberObj::~CMemberObj()
{
    std::cout << "~CMemberObj()" << std::endl;
}
