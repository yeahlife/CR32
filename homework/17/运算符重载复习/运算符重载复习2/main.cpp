#include "stdafx.h"

class CStudent {
public:
    CStudent() {

    }

    ~CStudent() {
        printf("~CStudent()");
    }

    void foo() {
        printf("CStudent\r\n");
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
    CPointer pt(new CStudent);
    
    // ��Ҫ��pt����->��������أ�����ֵ������pt����ָ������ָ��
    pt->foo();
    // ��Ҫ��pt����*��������أ�����ֵ������pt����ָ������ָ���ַ
    (*pt).foo();

    return 0;
}
/*
��������أ�
�з������ͺͲ����б�
*/
