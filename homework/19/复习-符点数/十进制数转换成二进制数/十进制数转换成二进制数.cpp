// 十进制数转换成二进制数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
    int x = -1234567;

    //整数为负数，取补，使其为正数
    if (x < 0) {
        cout << '-';
        x = -x;
    }

    //过滤前导0
    int i = 31;
    while (!(x & 1<<i)) {
        i--;
    }

    //移位 & 1，求当前位是0或1
    for (; i >= 0; --i) {
        cout << (x>>i & 1);
        //或者cout << (x & 1<<i);
    }
    cout << "\r\n";

    return 0;
}

/*
output:
-100101101011010000111
*/

