// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

/*
2. 写一个有重载operator++的类。。试着用前缀和后缀的形势重载，看看编译器会给出什么警告。
*/

#include "stdafx.h"

class CInt
{
private:
    int m_int;

public:
    CInt(int n)
    {
        m_int = n;
    }
    int operator++()
    {
        return ++m_int;
    }

    int operator++(int)
    {
        return m_int++;
    }
};
int main()
{
    CInt n = 3;
    n++;
    ++n;
    printf("\r\n");

    return 0;
}



