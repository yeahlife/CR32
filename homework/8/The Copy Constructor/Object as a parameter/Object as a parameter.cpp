/*
����ֱ��¼�ڱʼ�����
*/
/*
������Ϊ����
Object as a parameter
*/

#include "stdafx.h"
#include <iostream>

//����һ�����������ڴ�������
class CTest {
public:
    //���캯��
    CTest(int n = 1)
        :m_nTest(n)
    {
        std::cout << "CTest()" << std::endl;
    }

    //��������
    CTest(CTest& obj)
    {
        std::cout << "CTest(CTest& obj)" << std::endl;
        //�������Ա��ֵ
        m_nTest = obj.m_nTest;
    }

    //=���������
    CTest& operator=(CTest& obj)
    {
        std::cout << "CTest& operator=(CTest& obj)" << std::endl;
        m_nTest = obj.m_nTest;
    }

    //��������
    ~CTest()
    {
        std::cout << "~CTest()" << std::endl;
    }

    //����Ա����
    void foo_test() const 
    {
        //m_nTest = 1; // ����Ա�����������޸ĳ�Աֵ
        //mutable ���εĳ�Աֵ�����޸ģ�������Щì��
        m_n_mutable_Test = 2;
        //�Ի��߿���ʹ��ָ������ǿת�ﵽ�޸�ֵ��Ŀ��
        CTest* p = const_cast<CTest*>(this);
        p->m_nTest = 3; //���캯����m_nTest��ֵΪ1�����ǰ����޸�Ϊ��3

        std::cout << "m_nTest = " << m_nTest << std::endl;
    }

    //��ͨ��Ա����
    void foo_test1()
    {
        m_nTest = 2; //��ͨ��Ա���������޸ĳ�Աֵ
        std::cout << "m_nTest = " << m_nTest << std::endl;
    }

private:
    int m_nTest;
    mutable int m_n_mutable_Test;
};

void foo_argRef(const CTest& tRefArg) {
    tRefArg.foo_test();
}

int main()
{
    CTest t;
    foo_argRef(t);

    return 0;
}


