// 8 emptyClass emptyStruct.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
8.��֤����Ϳսṹ��Ĵ�С��
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

    std::cout << "empty class size is�� " << nEmptyClassSize << std::endl;
    std::cout << "empty struct size is: " << nEmptyStructSize << std::endl;

    return 0;
}
/*
output:
empty class size is�� 1
empty struct size is: 1
*/
