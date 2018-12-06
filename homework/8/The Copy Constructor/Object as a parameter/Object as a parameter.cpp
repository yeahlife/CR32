/*
代码分别记录在笔记中了
*/
/*
对象作为参数
Object as a parameter
*/

#include "stdafx.h"
#include <iostream>

//创建一个测试类用于创建对象
class CTest {
public:
    //构造函数
    CTest(int n = 1)
        :m_nTest(n)
    {
        std::cout << "CTest()" << std::endl;
    }

    //拷贝构造
    CTest(CTest& obj)
    {
        std::cout << "CTest(CTest& obj)" << std::endl;
        //给对象成员赋值
        m_nTest = obj.m_nTest;
    }

    //=运算符重载
    CTest& operator=(CTest& obj)
    {
        std::cout << "CTest& operator=(CTest& obj)" << std::endl;
        m_nTest = obj.m_nTest;
    }

    //析构函数
    ~CTest()
    {
        std::cout << "~CTest()" << std::endl;
    }

    //常成员函数
    void foo_test() const 
    {
        //m_nTest = 1; // 常成员函数不允许修改成员值
        //mutable 修饰的成员值可以修改，尽管有些矛盾
        m_n_mutable_Test = 2;
        //以或者可以使用指针类型强转达到修改值的目的
        CTest* p = const_cast<CTest*>(this);
        p->m_nTest = 3; //构造函数中m_nTest的值为1，我们把它修改为了3

        std::cout << "m_nTest = " << m_nTest << std::endl;
    }

    //普通成员函数
    void foo_test1()
    {
        m_nTest = 2; //普通成员函数可以修改成员值
        std::cout << "m_nTest = " << m_nTest << std::endl;
    }

private:
    int m_nTest;
    mutable int m_n_mutable_Test;
};

void foo_argRef(const CTest& tRefArg) {
    tRefArg.foo_test();
}

int main()
{
    CTest t;
    foo_argRef(t);

    return 0;
}


