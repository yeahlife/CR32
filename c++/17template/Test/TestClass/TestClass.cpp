// TestClass.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//��ģ��

template<typename T, int SIZE = 101, int SIZE2 = 102>
class CTest {
public:
    CTest(T n) {
        m_nTest = n;
    }

private:
    T m_nTest;
    int m_nAry[SIZE];
};


int main()
{
    //����ģ��ʵ��
    //��ģ�������ʽʵ����
    int n = 100;
    CTest<int> t(1);


    return 0;
}

