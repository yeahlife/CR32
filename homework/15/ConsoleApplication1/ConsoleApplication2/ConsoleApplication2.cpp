// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
2. дһ��������operator++���ࡣ��������ǰ׺�ͺ�׺���������أ����������������ʲô���档
*/

#include "stdafx.h"

class CInt
{
private:
    int m_int;

public:
    CInt(int n)
    {
        m_int = n;
    }
    int operator++()
    {
        return ++m_int;
    }

    int operator++(int)
    {
        return m_int++;
    }
};
int main()
{
    CInt n = 3;
    n++;
    ++n;
    printf("\r\n");

    return 0;
}



