// 4_1 default.cpp : 定义控制台应用程序的入口点。
//

/*
4.举例说明关键字=default,=delete,explicit在类中的作用。
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

class NoCopyCstor {
public:
    NoCopyCstor() = default; //显式缺省
    // 使用"=delete"同样可以有效阻止用户
    // 错用拷贝构造函数
    NoCopyCstor(const NoCopyCstor&) = delete; // 显式删除
};

int main()
{
    NoCopyCstor a;
    //NoCopyCstor b(a);//无法通过编译
    return 0;
}
/*
c++11 =default作用

1. 如果程序员在类中自定义了函数版本，则编译器不会再为该类自动生成默认版本。
但是有时候会忘记，比如声明了带参数的构造函数，忘记声明无参数的构造函数，这样
编译器会提示。但是更严重的是，一旦声明了自定义版本的构造函数，则有可以导致我们定义
的类型不再在POD的。啥是POD先不管呢！
案例有些还看不太懂，在书籍深入理解C++11第7章

2. 限制一些默认函数的生成，最典型的是禁止使用拷贝构造函数。

具体案例还是看书籍上写的吧，这里我就把default delete这个写一下。
*/

/*
c++11“=delete”
1. 会指示编译器不生成函数的缺省版本
2. 避免一些不必要的隐式数据类型转换
*/
