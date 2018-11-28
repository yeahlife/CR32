// 7 new newsquare delete deletesquare.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class CTest {
public:
    CTest()
    {
        std::cout << "CTest()" << std::endl;
    }
    ~CTest()
    {
        std::cout << "~CTest()" << std::endl;
    }

    int n;
    float fn;

};

int main()
{
    // 申请N个CTest对象的内存空间
    CTest* pTest = new CTest[3];

    //delete pTest; //异常
    delete pTest;
    //delete[] pTest;

    return 0;
}
/*
0x00074C76  fd fd fd fd  ????
0x00074C80  03 00 00 00  ....
0x00074C84  cd cd cd cd  ????
0x00074C88  cd cd cd cd  ????
0x00074C8C  cd cd cd cd  ????
0x00074C90  cd cd cd cd  ????
0x00074C94  cd cd cd cd  ????
0x00074C98  cd cd cd cd  ????
0x00074C9C  fd fd fd fd

delete pTest会出现异常
异常的原因：
难过new CTest[3]后，编译器返回给我们的对象的指针指向的内存地址是 0x00074C84
当我们用delete[] pTest释放内存的时候，编译器会自动计算要释放的堆内存。
但是当我们使用delete pTest的时候，编译器内部依然会按照它的模式去查找这块堆内存
类似这个样子的。delete (CTest*)((char*)pTest - 4)，那计算后的指针指向的内存地址就是0x00074C80，
释放，最终导致堆内存的不平衡，引起异常。

delete[] pTest正常释放内存
*/