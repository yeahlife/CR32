#include "stdafx.h"
#include "clock.h"

//定义类中的函数指针
typedef int(__stdcall tagClock::*PFN_SetTimeClass)(int nH, int nM, int nS);
//参数传递：寄存器 栈
// thiscall --> 用于类的成员函数的调用约定， 编译器内部使用
// fastcall
// cdecl
// stdcall

int main()
{
    tagClock cl;

    //第1种调用成员函数的形式
    cl.SetTime(1, 2, 3);

    //第2种调用成员函数的形式，通过函数指针
    PFN_SetTimeClass pfn_class;
    pfn_class = &tagClock::SetTime;
    (cl.*pfn_class)(11, 21, 31);

    //第3种调用成员函数的形式，通过对类对象的引用
    tagClock* pCL = &cl;
    //PNF_SetTimeClass pfn_class;
    //pfn_class = &tagClock::SetTime;
    (pCL->*pfn_class)(10, 20, 30);

    return 0;
}