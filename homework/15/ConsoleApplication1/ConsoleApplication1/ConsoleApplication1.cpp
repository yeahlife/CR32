// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

/*
完善MyString加入运算符重载，
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <memory>
using namespace std;

class CMystring
{
private:
    char m_szBuf[256];

public:
    CMystring(char* psz)
    {
        strcpy(m_szBuf, psz);
    }

    CMystring& operator=(CMystring &str);

    void append(CMystring& str)
    {
        strcat(str.m_szBuf, m_szBuf);
    }
};

CMystring operator+(CMystring str, char* psz)
{
    CMystring tmp = psz;
    tmp.append(str);

    return str;
}

CMystring& CMystring::operator=(CMystring &str)
{
    memcpy(m_szBuf, str.m_szBuf, 256);
    printf("void operator=(CMystring str，char* psz)");
    return str;
}

int main()
{
    CMystring str = "Hello";
    str = str + "world";
    printf("\r\n");
    
    return 0;
}

