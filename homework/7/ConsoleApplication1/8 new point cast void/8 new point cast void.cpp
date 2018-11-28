// 8 new point cast void.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CTest
{
public:
    CTest();
    ~CTest();

private:

};

CTest::CTest()
{
    std::cout << "CTest()" << std::endl;
}

CTest::~CTest()
{
    std::cout << "~CTest()" << std::endl;
}

int main()
{
    void* ptr = new CTest;
    delete ptr;

    return 0;
}

/*
new Class CTest 创建的对象指针类型是CTest类型的
如果转换成void *，再调用delete释放内存，会报错
不会执行析构函数

删除类的指针调用析构，如果转化为void就不调用析构

*/

