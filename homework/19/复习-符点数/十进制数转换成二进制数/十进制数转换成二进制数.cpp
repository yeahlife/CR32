// ʮ������ת���ɶ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
    int x = -1234567;

    //����Ϊ������ȡ����ʹ��Ϊ����
    if (x < 0) {
        cout << '-';
        x = -x;
    }

    //����ǰ��0
    int i = 31;
    while (!(x & 1<<i)) {
        i--;
    }

    //��λ & 1����ǰλ��0��1
    for (; i >= 0; --i) {
        cout << (x>>i & 1);
        //����cout << (x & 1<<i);
    }
    cout << "\r\n";

    return 0;
}

/*
output:
-100101101011010000111
*/

