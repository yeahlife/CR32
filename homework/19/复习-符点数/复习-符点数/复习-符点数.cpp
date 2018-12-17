// 复习-符点数.cpp : 定义控制台应用程序的入口点。
//

/*
符点数的位码
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
    float f = 19.2F;
    unsigned int* pa = reinterpret_cast<unsigned int*>(&f);

    for (int i = 31; i >= 0; i--) {
        cout << (*pa >> i & 1) << (i == 31 || i == 23 ? "-" : "");
    }
    cout << "\r\n";

    return 0;
}
/*
output:
0-10000011-00110011001100110011010
*/

