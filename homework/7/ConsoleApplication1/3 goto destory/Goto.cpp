#include "stdafx.h"
#include "Goto.h"
#include <iostream>

CGoto::CGoto()
{
    std::cout << "CGoto()" << std::endl;
}


CGoto::~CGoto()
{
    std::cout << "~CGoto()" << std::endl;
}

void CGoto::foo()
{
    {
        for (int i = 0; i < 10; i++) {
            std::cout << i << std::endl;
            if (i>6) {
                goto label;
            }
        }
        
    }
label:
    std::cout << "CGoto::foo()" << std::endl;
}
