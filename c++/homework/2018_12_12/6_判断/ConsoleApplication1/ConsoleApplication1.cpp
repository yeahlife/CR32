/*
��дһ�����е�һ���Ͳ�����T)�ĺ���ģ�壬
��������4������������
һ��T�����飬
һ����ʼ����ֵ��
ָ������Ĵ���Ϊʲô�޷����룿
*/

#include "StdAfx.h"
#include <stdlib.h>
#include <iostream>

template<class T> 
double pythag(T a, T b, T c) 
{
    return (-b + sqrt(double(b*b - 4 * a*c))) / 2 * a;
}

int main()
{
    pythag(1, 2, 3);
    pythag(1.0, 2.0, 3.0);
    //pythag(1, 2.0, 3.0);
    pythag<double>(1, 2.0, 3.0);

    /*
        �����ǵ����е�����
        ��Ϊ�����д��ڶ�����
        ��������֪����ʹ��int ����double
        ��������ʾ�ػ�Ϊdouble ���Ի�����ʹ��
    */
    system("pause");
    return 0;
}


