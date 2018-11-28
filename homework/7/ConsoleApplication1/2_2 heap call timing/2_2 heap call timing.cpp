// 2_2 heap call timing.cpp : 定义控制台应用程序的入口点。
//
/*
2.举例说明构造函数和析构函数的调用时机（栈对象，全局对象，堆对象,类对象成员）。
*/

#include "stdafx.h"
#include "HeapObj.h"
#include <iostream>

int main()
{
    // 申请堆内存
    CHeapObj *ptr = new CHeapObj();
    ptr->ShowMsg();

    // 需要手动调用delete ptr 来释放内存
    delete ptr;

    return 0;
}

/*
堆对象，动态建立类对象

使用new运算符将对象创建在堆内存中。

调试：
13行打断点F9，
观察ptr，发现在堆中开辟了一段内存空间，
并且调用了CHeapObj中的构造函数，将成员值初始化
ptr就是指向我们CHeampObj对象类型的指针变量。

然后ptr->ShowMsg();打印一段信息。hello heap object

继续执行程序，当程序执行完毕，
程序没有调析构函数，
堆内存没有释放，
需要我们手动调用delete运算符来释放申请的内存。
delete ptr;
*/

/*
CHeapObj()
hello heap object
*/

/*
delete ptr

当我们手动执行堆内存释放的时候，会调用析构函数
CHeapObj()
hello heap object
~CHeapObj()
*/