/*
    ʹ�����������ʵ�ֱ��壬֧��int float char*�����͡�
*/

#include "StdAfx.h"
#include <stdlib.h>
#include <iostream>

template<typename T>
T GetSum(T A, T B)
{
    return A + B;
}

template<>
char* GetSum(char* A, char* B)
{
    strcat(A, B);
    return A;
}

/*------------------����ģ���ػ�-----------------*/

template<typename T>
class TestClass
{
public:
    TestClass()
    {
        m_T = 233;
    }

    void MyPrint()
    {
        std::cout << m_T << std::endl;
    }

private:
    T m_T;
};

template<>
class TestClass<char*>
{
public:
    TestClass()
    {
        m_T = "Hello";
    }
    void MyPrint()
    {
        std::cout << m_T << std::endl;
    }

private:
    char* m_T;
};

/*------------------��ģ���ػ�-----------------*/

template<typename T>
class TestClass2 
{
public:
    TestClass2()
    {
        m_T = 1.1;
    }

    void MyPrint()
    {
        std::cout << m_T << std::endl;
    }

private:
    static T m_T;
};

template<typename T>
T TestClass2<T>::m_T;


int main()
{
    char szA[16]  = "Hello";
    char szB[] = " World!";
    std::cout << GetSum(5, 6) << std::endl;
    std::cout << GetSum(szA, szB) << std::endl;
    /*------------------����ģ���ػ�-----------------*/

    TestClass<int> Test1;
    Test1.MyPrint();
    TestClass<char*> Test2;
    Test2.MyPrint();
    /*------------------��ģ���ػ�-----------------*/
    /*---------------��ģ�������ʾ����-----------------*/

    TestClass2<double> Test3;
    Test3.MyPrint();
    /*------------------��̬��Ա�����ػ�-----------------*/
    system("pause");
    return 0;
}


