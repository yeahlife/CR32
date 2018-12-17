// 运算符重载 CMystring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

class CMystring {
public:
    CMystring() {
        printf("CMystring()\r\n");
    }

    CMystring(char* psz) {
        printf("CMystring(char* psz)\r\n");
        strcpy(m_szBuf, psz);
    }

    void append(CMystring& str) {
        strcat(m_szBuf, str.m_szBuf);
    }

    char& operator[](int nIndex);

    // 友元
    // 在std::ostream类以外定义，需要向std::ostream说明
    // 就好比告诉std::ostream说，我是你的朋友，请让我有对你访问的权限
    friend std::ostream& operator<<(std::ostream& cout, CMystring& str);

    friend void operator+(CMystring str, char* psz);

    friend CMystring operator+(char* psz, CMystring str);

    CMystring& operator=(CMystring& obj);
    void operator=(char* psz);

private:
    char m_szBuf[256];
};

CMystring& CMystring::operator=(CMystring& obj) {
    memcpy(m_szBuf, obj.m_szBuf, 256);
    
    printf("CMystring& CMystring::operator=(CMystring& obj)\r\n");

    return *this;
}

void CMystring::operator=(char* psz) {
    printf("void operator=(char* psz)");
}

CMystring operator+(char* psz, CMystring str) {
    printf("CMystring operator+(char* psz, CMystring str)");

    CMystring tmp = psz;
    tmp.append(str);

    return tmp;
}

char& CMystring::operator[](int nIndex) {
    return m_szBuf[nIndex];
}

std::ostream& operator<<(std::ostream& cout, CMystring& str) {
    cout << str.m_szBuf;
    return cout;
}

void operator+(CMystring str, char* psz) {
    printf("operator+(CMystring str, char* psz)");
}

int main()
{
    CMystring str = " World!";

    // []运算符重载，
    // 参数是int类型数组，表示访问字符串对象数组的下标
    // 返回值char类型的地址，指向字符串对象数组对应位置的地址
    // char ch指向这个str对象数组中某一字符对应位置的值
    //char ch = str[0];
    //str[0] = 'a';

    // << 运算符重载，
    // 这种方式也可以重载，但是有悖于<< 运算符原来的语义
    // 一般情况下重载运算符不要脱离原来运算符使用的语义和上下文情境，以免给人造成干扰
    // 重载形式 void operator<<(char* psz);
    //str << "123";

    // << 运算符重载
    // 经过查文档，extern std::ostream cout;
    // cout 是指向std::ostream对象的流
    // 这里要对std::cout << 重载的话，就需要将对象指向std::ostream对象流
    // cout 和 " World!"都参与重载的运算，返回cout对象
    // " World"
    //std::cout<< " World!" << std::endl;
    // str 是CMystring 的对象，重载cout
    //std::cout << str << std::endl;

    CMystring str1;
    CMystring str2;
    // + 运算符重载
    // 参数 CMystring str的对象和一个char* 字符指针，返回值看情况而定
    //str + "Hello";

    //int n, k, j;
    //n = k = j + 1;
    str2 = str1 = "Hello" + str;

    // int n = 1 + 2;
    //std::string str = "Hello";

    //str = str + " World!";

    //str.append(" World!");

    return 0;
}

