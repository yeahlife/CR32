/*
深拷贝
*/

#include "stdafx.h"
#include <iostream>

class CStudent {
public:
    //构造函数
    CStudent(char* pName, int nGender = 1)
        :m_nGender(nGender) //初始化参数列表
    {
        //测试是否发生 构造函数
        std::cout << "CStudent(int nGender)" << std::endl;

        //申请堆空间，保存姓名
        m_nName = new char[strlen(pName) + 1];
        //拷贝姓名
        strcpy_s(m_nName, strlen(pName) + 1, pName);
    }

    //可以禁用拷贝构造
    //CStudent(CStudent& obj) = delete;
    //也可以自己实现拷贝构造
    //功能的话可以和构造函数的一致
    CStudent(CStudent& obj) //这里obj就表示的是CStudent这个对象的引用
    {
        //测试是否发生 拷贝构造
        std::cout << "CStudent(CStudent& obj)" << std::endl;

        //初始化参数列表赋初值的方式这里就不可以使用了
        m_nGender = obj.m_nGender;
        //申请堆空间，保存姓名
        m_nName = new char[strlen(obj.m_nName) + 1];
        //拷贝姓名
        strcpy_s(m_nName, strlen(obj.m_nName) + 1, obj.m_nName);
    }

    //那仅仅重新定义拷贝构造函数后运行，发现并没有达到深拷贝的目的
    //这里还需要 =运算符重载
    CStudent& operator=(CStudent& obj)
    {
        //测试是否发生 =运算符重载
        std::cout << "CStudent& operator=(CStudent& obj)" << std::endl;

        //不允许拷贝自身
        if (m_nName == obj.m_nName) {
            return *this; //返回当前对象类型的指针
        }
        //释放申请的堆空间
        if (m_nName != NULL) {
            delete[] m_nName;
        }
        m_nName = NULL;
        //初始化参数列表赋初值的方式这里就不可以使用了
        m_nGender = obj.m_nGender;
        //申请堆空间，保存姓名
        m_nName = new char[strlen(obj.m_nName) + 1];
        //拷贝姓名
        strcpy_s(m_nName, strlen(obj.m_nName) + 1, obj.m_nName);
        //需要返回值
        return *this; //返回当前对象类型的指针
    }

    //析构函数
    ~CStudent()
    {
        //测试是否发生析构
        std::cout << "~CStudent()" << std::endl;

        //释放申请的堆空间
        if (m_nName != NULL) {
            delete[] m_nName;
        }
        m_nName = NULL;
    }

private:
    int m_nGender; //性别
    char* m_nName; //姓名
};

int main()
{
    char szName[] = "zhangsan";
    //申请一个CStudent类对象，名为stu1
    //调用CStudent类的构造函数
    CStudent stu1(szName, 1);
    
    //申请一个CStudent类对象，名为stu2
    //调用CStudent类的构造函数
    //CStudent stu2("1");
    //stu2 = stu1;//发生 =运算符重载，属于深拷贝

    //申请一个CStudent类对象，名为stu2
    //调用CStudent类的构造函数
    CStudent stu2(stu1);//发生 拷贝构造，属于深拷贝

    return 0;
}