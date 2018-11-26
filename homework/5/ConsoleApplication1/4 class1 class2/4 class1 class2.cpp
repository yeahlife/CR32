// 4 class1 class2.cpp : 定义控制台应用程序的入口点。
//
/*
4.编写两个类，每个类都有一个成员函数，该函数中把一个指针指向另一个类的一个对象。
在函数main()中创建两个实例对象，调用前面每一个类中的成员函数。
*/

#include "stdafx.h"
#include "test.h"

int main()
{
    //访问对象A通过指向B对象的成员指针访问B对象成员函数ShowB()
    tagA sta = { 0 };
    sta.b->ShowB();
    //访问对象B通过指向A对象的成员指针访问A对象成员函数ShowA()
    tagB stb = { 0 };
    stb.a->ShowA();

    return 0;
}

