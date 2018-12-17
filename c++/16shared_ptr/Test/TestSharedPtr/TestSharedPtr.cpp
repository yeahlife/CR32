// TestSharedPtr.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


//�򵥰汾������ָ��
//����ָ����ʲô��
//1. ����ָ�뱾���Ƕ��󣬵���ʹ��������ָ�롣
//2. ��ָ�룺������->��*
//Ϊʲô��Ҫʹ������ָ�룿
//  �ѿռ�ͨ����Ҫ�ֶ��ͷţ����ѵ�ָ����뵽����ָ����
//��������ָ������Զ��������ص㣬�Ӷ��Զ��ͷŶѿռ䡣

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

class CRefCount {
public:
    CRefCount(CStudent* pStu) {
        m_pStu = pStu;
        m_nCount = 1;
    }

    void AddRef() {
        m_nCount++;
    }

    void DelRef() {
        if (--m_nCount == 0) {
            delete m_pStu;
            delete this;
        }
    }

private:
    CStudent* m_pStu;
    int m_nCount;
};

class CSharedPtr {
public:
    explicit CSharedPtr(CStudent* pStu) {
        m_pStu = pStu;
        m_pRefCount = new CRefCount(pStu);
    }

    CSharedPtr(CSharedPtr& obj) {
        m_pStu = obj.m_pStu;

        m_pRefCount = obj.m_pRefCount;
        m_pRefCount->AddRef();
    }

    CSharedPtr& operator=(CSharedPtr& obj) {
    
        if (&obj == this) {
            return *this;
        }

        m_pRefCount->DelRef();

        m_pStu = obj.m_pStu;
        m_pRefCount = obj.m_pRefCount;
        m_pRefCount->AddRef();

    }


    ~CSharedPtr() {
        m_pRefCount->DelRef();
        
    }

    CStudent* operator->() {
        return m_pStu;
    }

    CStudent& operator*() {
        return *m_pStu;
    }


private:
    CStudent* m_pStu;
    CRefCount* m_pRefCount;
};


int main()
{
    CStudent* pStu1 = new CStudent;
    CSharedPtr p(pStu1);
    CSharedPtr p2 = p;

    CStudent* pStu2 = new CStudent;
    CSharedPtr p3(pStu2);
    p2 = p2;
    p2 = p3;

    return 0;
}

