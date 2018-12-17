#include "stdafx.h"
#include <string>
#include <iostream>

class CInt {
public:
    CInt(int n) {
        printf("CInt()\r\n");
        m_int = n;
    }

    // pre ++
    int operator++() {
        return ++m_int;
    }

    // post ++
    int operator++(int) {
        return m_int++;
    }

    void* operator new(size_t cb) {
        void* p = new char[cb];
        return p;
    }

private:
    int m_int;
    int m_nTest;
};

int main()
{
    // 这条语句的意思是大概是，创建一个CInt 类对象n ，将1 传入n对象的构造函数中
    //CInt n = 1;
    // 这里这个::，表示全局作用域符
    //CInt* pN = ::new CInt(1); 
    // 上面这种情况下，可以省略:: 全局作用域符，效果一样，暂时先这么理解，不清楚对不对
    //CInt* pN2 = new CInt(1);


    CInt n = 1;
    // n是CInt类的对象，对对象执行++操作，需要对++运算符重载
    // 后置++ 运算符重载，有参 int，返回值类型是 int类型
    // 为什么要有一个int参数呢？这个参数也没用使用到，
    // 为了解决函数原型必须不同的问题，重载函数必须拥有不同的函数原型，为了绕过这一语法限制就加了一个int来区别，没其他意思
    // 后置++ 的返回值类型是const 右值
    n++;
    // 前置++ 运算符重载，无参，返回值类型是int 类型
    // 前置++ 的返回值类型是左值引用
    // 前置++ 的返回值类型为什么是左值引用？
        // 为了与内置类型的行为保持一致，前置++ 返回的总是被自增的对象本身。
    ++n;

    // std::string的对象str1 指向了字符串数组对象，需要对new()运算符重载
    // new() 运算符重载，参数接受一个size_t 类型的值，返回值是指向这个字符串数组对象的指针
    // 返回值的指针类型，void* 类型比较合适，通过性
    std::string str1 = " World!";
    // 修改str1 对象的第1 个元素
    str1[0] = 'b';

    return 0;
}

