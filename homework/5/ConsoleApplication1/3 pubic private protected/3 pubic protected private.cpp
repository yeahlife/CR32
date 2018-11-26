// 3 pubic private protected.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "test.h"

int main()
{
    // 声明tagTest类的变量t
    tagTest t;
    
    // 测试 public
    //t.SetN1(1); // n1 = 1
    //t.GetN1();  // 1
    //t.n1;       // 1

    // 测试 protected
    //t.SetN1(2);
    //t.GetN2();
    //t.n2;
    // protected 属性的元素无法访问

    // 测试 privated
    //t.SetN3(3);
    //t.GetN3();
    //t.n3();
    // privated 属性的元素无法访问

    return 0;
}

