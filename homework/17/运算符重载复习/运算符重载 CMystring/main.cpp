// ��������� CMystring.cpp : �������̨Ӧ�ó������ڵ㡣
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

    // ��Ԫ
    // ��std::ostream�����ⶨ�壬��Ҫ��std::ostream˵��
    // �ͺñȸ���std::ostream˵������������ѣ��������ж�����ʵ�Ȩ��
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

    // []��������أ�
    // ������int�������飬��ʾ�����ַ�������������±�
    // ����ֵchar���͵ĵ�ַ��ָ���ַ������������Ӧλ�õĵ�ַ
    // char chָ�����str����������ĳһ�ַ���Ӧλ�õ�ֵ
    //char ch = str[0];
    //str[0] = 'a';

    // << ��������أ�
    // ���ַ�ʽҲ�������أ����������<< �����ԭ��������
    // һ������������������Ҫ����ԭ�������ʹ�õ�������������龳�����������ɸ���
    // ������ʽ void operator<<(char* psz);
    //str << "123";

    // << ���������
    // �������ĵ���extern std::ostream cout;
    // cout ��ָ��std::ostream�������
    // ����Ҫ��std::cout << ���صĻ�������Ҫ������ָ��std::ostream������
    // cout �� " World!"���������ص����㣬����cout����
    // " World"
    //std::cout<< " World!" << std::endl;
    // str ��CMystring �Ķ�������cout
    //std::cout << str << std::endl;

    CMystring str1;
    CMystring str2;
    // + ���������
    // ���� CMystring str�Ķ����һ��char* �ַ�ָ�룬����ֵ���������
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

