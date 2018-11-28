// 6 malloc new delete.cpp : 定义控制台应用程序的入口点。
//

/*
6.c++中能不能使用malloc来创建对象，有什么问题？举例说明new / delete的作用和好处。
*/

#include "stdafx.h"
#include <iostream>

class CAdvantage {
public:
    CAdvantage()
    {
        std::cout << "CAdvantage()" << std::endl;
    }
    ~CAdvantage()
    {
        std::cout << "~CAdvantage()" << std::endl;
    }

    int n;
    float fn;

};

int main()
{
    // 申请N个CAdvantage对象的内存空间
    CAdvantage* pTest = new CAdvantage[3];

    //delete pTest; //异常
    delete[] pTest;

    return 0;
}

/*
output:
CAdvantage()
CAdvantage()
CAdvantage()
~CAdvantage()
~CAdvantage()
~CAdvantage()
*/

/*
【转】https://blog.csdn.net/leikun153/article/details/80612130
C++中可以使用malloc/free，

1. 它们是C++/C语言的标准库函数，
    new/delete是C++运算符，它们都可以进行动态内存和释放内存。

2. 对于非内部数据类型的对象而言，
    只用malloc/free无法满足动态对象的要求。这是因为对象在创建的同时
    需要自动执行构造函数，对象在消亡之前要自动执行析构函数，而由于
    malloc/free是库函数而不是运算符，不在编译器的控制权限内，也就不能
    自动执行构造函数和析构。因此，不能将执行构造函数和析构函数的任务强加给
    malloc/free。所以，在C++中需要一个能完成动态内存分配和初始化工作的
    运行符new，以及一个能完成清理和释放内存工作的运算符delete。

3. new建立的是一个对象，
   malloc分配的是一块内存区域，用指针来访问，并且可以在区域里移动指针。

4. 对内部数据类型，由于没有构造函数和析构函数的要求，
    malloc/free和new/delete的作用是等价的，
    都是用来申请动态内存和释放内存。
*/

/*
内部数据类型：
    是编译器本身就认识的，不需要用户自定义。
    如：基本数据类型：int,char,double等都是内部数据类型

非内部数据类型：
    不是编译器本身就认识的，需要用户自己定义才能让编译器识别的。
    如：由class,struct,union等关键字修饰的变量都是非内部数据类型。
*/

/*
为会么库函数不在编译器控制权限内，而运算符在？
    库函数是已经编译的代码，编译器不会在编译检查，由链接器将库同用户写的代码合成exe文件。
    而运算符是否正确，编译器在编译扫描分析时就可以判定。
*/

/*
new/delete
new[]/delete[]
要配套使用
*/

/*
new和delete机制
new操作：
1. 调用operator new函数，分配足够大的原始的未类型化的内存，
2. 运行该类型相应的构造函数，在上一步分配的内存基础上进行初始化对象
3. 返回新分配并指向构造的对象的指针

delete操作：
1. 对指针所指向的对象运行析构函数
2. 调用operator delete函数，释放该对象所用的内存
*/

