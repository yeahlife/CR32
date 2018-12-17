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
    //智能指针
    // <CStudent> 可以简单理解成显示说明，我要指向的这个对象是谁
    // 这里就是说有一个指针，指向了一个对象，这个指向的对象是CStudent类
    std::shared_ptr<CStudent> pt(new CStudent);
    // 同上理解
    // 之前那种写法会有析构的问题，两个对象同时指向同一块内存区域
    // 但是智能指针帮我们解决了这个问题，这时候执行析构的时候只会一次了，
    // 至于智能指针的原理，再往后来理解它的原理。
    std::shared_ptr<CStudent> pt2 = pt;

    // 需要对->运算符重载，无参数，返回值类型是指向CStudent的指针
    pt->foo(); 
    // 需要对*运算符重载，无参数，返回值类型是指向CStudent的指针的地址
    (*pt).foo();

    return 0;
}
/*
运算符重载：
有返回类型和参数列表
*/
