// 错误的引用计数带来的问题.cpp : 定义控制台应用程序的入口点。
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
由于CPointer中有一个指向CStudent对象的指针，
CPointer执行析构的时候，是释放掉它指向的那个对象，
这时候CPointer又创建一第二个对象，将pt赋值给pt2,
程序执行完毕，调用析构，第一次析构正常释放CPointer中指向CStudent的指针。
第二次释放的时候，会出现问题。因为指针指向的那块内存区域已经被释放。
*/

