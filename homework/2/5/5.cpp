// 5.cpp : Defines the entry point for the console application.
//

/*
创建一个函数，
使之参数为一个指向指针的指针的引用，要求该函数对其参数进行修改。
然后，在main()中调用这个函数。
*/

#include "stdafx.h"

void exchange(int*& n1, int*& n2) {
    int* k = n1;
    n1 = n2;
    n2 = k;
    return;
}

int main(int argc, char* argv[])
{
    int m = 1;
    int n = 2;

    int* pM = &m;
    int* pN = &n;

    exchange(pM, pN);
    
    return 0;
}
/*
VC6好像没交换这两值啊
*/

