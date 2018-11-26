// 9 member func point.cpp : 定义控制台应用程序的入口点。
//

/*
9.使用成员函数指针来调用类中的成员函数。
*/
#include "stdafx.h"
#include "test.h"

// 定义一个类中的函数指针
typedef void(tagTest::*PFN_ShowMsgA)();
typedef void(tagTest::*PFN_ShowMsgB)();

int main()
{
    // 声明tagTest对象
    tagTest t;
    // 将函数指针指向对应的函数
    PFN_ShowMsgA pfn_showmsga;
    pfn_showmsga = &tagTest::ShowMsgA;
    // 通过成员函数指针调用相应函数
    (t.*pfn_showmsga)();

    // 同理调用ShowMsgB()
    PFN_ShowMsgB pfn_showmsgb;
    pfn_showmsgb = &tagTest::ShowMsgB;
    (t.*pfn_showmsgb)();

    return 0;
}

