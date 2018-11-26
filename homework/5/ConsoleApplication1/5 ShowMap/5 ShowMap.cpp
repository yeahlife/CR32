// 5 ShowMap.cpp : 定义控制台应用程序的入口点。
//

/*
5.创建一个有很多数据成员的类，这些成员分布在public,private和protected所指定的区域中。
增加一个成员函数showMap(),该成员函数打印出这些数据成员的名字和它们的地址。
如果有可能，在多个编译器、操作系统中编译运行这个程序，看目标代码中布局是否一样。
*/
#include "stdafx.h"
#include "test.h"

int main()
{
    tagTest t;
    t.SetN1(1);
    
    t.ShowMap();

    return 0;
}

