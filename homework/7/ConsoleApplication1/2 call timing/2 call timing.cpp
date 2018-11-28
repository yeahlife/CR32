// 2 call timing.cpp : 定义控制台应用程序的入口点。
//
/*
2.举例说明构造函数和析构函数的调用时机（栈对象，全局对象，堆对象,类对象成员）。
*/

#include "stdafx.h"
#include "StackObj.h"

int main()
{
    CStackObj stackobj;

    return 0;
}

/*
栈对象，静态建立类对象，
main函数中
实例化这个CStackObj类对象的时候，
编译器为对象在栈空间中分配一段内存，
是通过移动栈顶指针，挪出适当的空间，
然后通过调用构造函数形成一个栈对象。

程序执行完毕，内存空间自动释放。
*/
