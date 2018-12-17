#include "stdafx.h"
#include <iostream>
#include <memory>

class CStudent {
public:
    CStudent() {
        printf("CStudent()\r\n");
    }

    ~CStudent() {
        printf("~CStudent()\r\n");
    }

    void foo() {
        printf("CStudent foo()\r\n");
    }

private:
    int m_nGender;
};

class  CPointer {
public:
    CPointer(CStudent* pStu) {
        m_pStu = pStu;
    }

    ~CPointer() {
        delete m_pStu;
    }

    // pt-> ���������
    CStudent* operator->() {
        return m_pStu;
    }

    // (*pt)���������
    CStudent& operator*() {
        return *m_pStu;
    }

private:
    CStudent* m_pStu;
};

int main()
{
    //����ָ��
    // <CStudent> ���Լ�������ʾ˵������Ҫָ������������˭
    // �������˵��һ��ָ�룬ָ����һ���������ָ��Ķ�����CStudent��
    std::shared_ptr<CStudent> pt(new CStudent);
    // ͬ�����
    // ֮ǰ����д���������������⣬��������ͬʱָ��ͬһ���ڴ�����
    // ��������ָ������ǽ����������⣬��ʱ��ִ��������ʱ��ֻ��һ���ˣ�
    // ��������ָ���ԭ�����������������ԭ��
    std::shared_ptr<CStudent> pt2 = pt;

    // ��Ҫ��->��������أ��޲���������ֵ������ָ��CStudent��ָ��
    pt->foo(); 
    // ��Ҫ��*��������أ��޲���������ֵ������ָ��CStudent��ָ��ĵ�ַ
    (*pt).foo();

    return 0;
}
/*
��������أ�
�з������ͺͲ����б�
*/
