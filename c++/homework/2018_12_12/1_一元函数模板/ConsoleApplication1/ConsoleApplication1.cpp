
#include "StdAfx.h"
#include <stdlib.h>
#include <iostream>

template<typename T>
T GetMax(T A)
{
    return A;
}

template<>
int GetMax(int A)
{
    return A;
}

int GetMax(int A)
{
    return A;
}

int main()
{
    std::cout <<GetMax(1.2f) <<std::endl;
    std::cout << GetMax(2) << std::endl;

    //����з�ģ�����ػ����Ƚ����� �����ǽ�ģ������
    system("pause");
    return 0;
}

