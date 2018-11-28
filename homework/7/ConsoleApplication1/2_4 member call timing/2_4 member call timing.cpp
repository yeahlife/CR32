// 2_4 member call timing.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MemberObj.h"

int main()
{
    CMemberObj memobj1;

    CMemberObj memobj2(2);

    return 0;
}
/*
output:
CMemberObj()
CMemberObj(int n)2
~CMemberObj()
~CMemberObj()
*/

/*
类对象成员：
1. 只有当对象成员所在的类有无参构造函数时，
编译器才会以隐式初始化列表的方式对对象成员进行初始化。
当一个类没有任何构造函数时，C++会产生一个默认无参构造函数;
一旦定义了任何构造函数，C++就不会产生无参构造函数了，
必须显示定义无参构造函数，或提供缺省参数的构造函数。

2. 当类具有对象成员时，应该采用初始化列表的方式对它进行初始化。

3. 对象成员的构造次序与它们在类中的声明次序相同，与它们在构造函数初始化列表中的次序无关。
*/

