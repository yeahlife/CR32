// ��������ü�������������.cpp : �������̨Ӧ�ó������ڵ㡣
//

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

private:
    CStudent* m_pStu;
};

int main()
{
    CStudent* pStu = new CStudent;
    pStu->foo();

    CPointer pt(new CStudent);
    CPointer pt2 = pt;

    return 0;
}

/*
����CPointer����һ��ָ��CStudent�����ָ�룬
CPointerִ��������ʱ�����ͷŵ���ָ����Ǹ�����
��ʱ��CPointer�ִ���һ�ڶ������󣬽�pt��ֵ��pt2,
����ִ����ϣ�������������һ�����������ͷ�CPointer��ָ��CStudent��ָ�롣
�ڶ����ͷŵ�ʱ�򣬻�������⡣��Ϊָ��ָ����ǿ��ڴ������Ѿ����ͷš�
*/

