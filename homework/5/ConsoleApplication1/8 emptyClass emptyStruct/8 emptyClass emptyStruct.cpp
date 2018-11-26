// 8 emptyClass emptyStruct.cpp : 定义控制台应用程序的入口点。
//

/*
8.验证空类和空结构体的大小。
*/

#include "stdafx.h"
#include "test.h"
#include <iostream>

using namespace std;

int main()
{
    int nEmptyClassSize = 0;
    int nEmptyStructSize = 0;

    nEmptyClassSize = sizeof(tagEmptyClass);
    nEmptyStructSize = sizeof(tagEmptyStruct);

    std::cout << "empty class size is： " << nEmptyClassSize << std::endl;
    std::cout << "empty struct size is: " << nEmptyStructSize << std::endl;

    return 0;
}
/*
output:
empty class size is： 1
empty struct size is: 1
*/
