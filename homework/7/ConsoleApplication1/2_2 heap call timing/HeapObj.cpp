#include "stdafx.h"
#include "HeapObj.h"
#include <iostream>

CHeapObj::CHeapObj()
{
    std::cout << "CHeapObj()" << std::endl;
    a = 1;
    b = 2;
    fNum = 3.14f;
}


CHeapObj::~CHeapObj()
{
    std::cout << "~CHeapObj()" << std::endl;
    a = 0;
    b = 0;
    fNum = 0.0f;
}

void CHeapObj::ShowMsg()
{
    std::cout << "hello heap object" << std::endl;
}