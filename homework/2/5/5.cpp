// 5.cpp : Defines the entry point for the console application.
//

/*
����һ��������
ʹ֮����Ϊһ��ָ��ָ���ָ������ã�Ҫ��ú���������������޸ġ�
Ȼ����main()�е������������
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
VC6����û��������ֵ��
*/

