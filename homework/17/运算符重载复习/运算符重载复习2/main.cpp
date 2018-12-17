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

    // pt-> 运算符重载
    CStudent* operator->() {
        return m_pStu;
    }

    // (*pt)运算符重载
    CStudent& operator*() {
        return *m_pStu;
    }

private:
    CStudent* m_pStu;
};

int main()
{
    CPointer pt(new CStudent);
    
    // 需要对pt对象->运算符重载，返回值类型是pt对象指向对象的指针
    pt->foo();
    // 需要对pt对象*运算符重载，返回值类型是pt对象指向对象的指针地址
    (*pt).foo();

    return 0;
}
/*
运算符重载：
有返回类型和参数列表
*/
