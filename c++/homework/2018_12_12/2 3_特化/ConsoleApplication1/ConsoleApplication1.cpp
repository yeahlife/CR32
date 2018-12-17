/*
��дһ�����е�һ���Ͳ�����T)�ĺ���ģ�壬
��������4������������
һ��T�����飬
һ����ʼ����ֵ��
һ����������ֵ��������Χ֮�ڵģ�
һ����ѡ��ĳ�ʼֵ��
��������ָ����Χ����������Ԫ��ֵ�ͳ�ʼֵ�ĺ͡�
��Ĭ�Ϲ��캯��ΪT���͵�������Ĭ�Ϸ�ʽ����ֵ��
*/

#include "StdAfx.h"
#include <stdlib.h>
#include <iostream>

template<typename T>
T GetSum(T* A, int nBegin , int nEnd, int nStart = 0)
{
    T nReulut = 0;
    for (int i = nStart; i < nEnd; i++)
    {
        nReulut += A[i];
    }
    return nReulut;
}

template<>
double GetSum(double* A, int nBegin, int nEnd, int nStart)
{
    double nReulut = 0;
    for (int i = nStart; i < nEnd; i++)
    {
        nReulut += A[i];
    }
    return nReulut;
}

template<>
int GetSum(int* A, int nBegin, int nEnd, int nStart)
{
    int nReulut = 0;
    for (int i = nStart; i < nEnd; i++)
    {
        nReulut += A[i];
    }
    return nReulut;
}

int main()
{
    int arynTemp[10] = { 1,2,3,4,5,6,7,8,9,10 };
    double arydblTemp[3] = { 1.1,2.7,3.6 };

    int nResult = GetSum(arynTemp, 0, 5);
    std::cout << nResult << std::endl;

    double dblResult = GetSum(arydblTemp, 0, 3);
    std::cout << dblResult << std::endl;

    nResult = GetSum<int>(arynTemp, 0, 8 ,0);
    std::cout << nResult << std::endl;

    dblResult = GetSum<double>(arydblTemp, 0, 2, 0);
    std::cout << dblResult << std::endl;
    //��ʾ��������������Ĭ�ϲ�
    system("pause");
    return 0;
}

