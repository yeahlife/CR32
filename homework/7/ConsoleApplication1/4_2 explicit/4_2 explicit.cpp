// 4_2 explicit.cpp : 定义控制台应用程序的入口点。
//

/*
4.举例说明关键字=default,=delete,explicit在类中的作用。
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

class ConverTo {
public:
    explicit ConverTo(int n)
    {
        std::cout << n << std::endl;
    }
};

int main()
{
    // 没有使用explicit关键字
    //int n = 10;
    //ConverTo ct(n); // 直接初始化，通过
    //ConverTo ct2 = n; // 拷贝构造初始化，编译通过
    //ConverTo ct3 = (ConverTo)(n); // 强制转化，编译通过

    // 使用explicit关键字
    int n = 10;
    //ConverTo ct(n); // 直接初始化，通过
    //ConverTo ct2 = n; // 拷贝构造初始化，编译不通过
    ConverTo ct3 = (ConverTo)(n); // 强制转化，编译通过
 
    return 0;
}

/*
explicit 关键字
用来声明构造函数为显式构造，避免一些不必要的隐式转换。
*/
