/*ʵ��MyString�г�Ա����MyString* stringcat(MyString *pString)
��Ϊһ����ַ�������,
�����������MyNumString(����˼�壬����ֻ�������ִ�),�����������Ӻ���Ҫ�üӷ�������������23,��34�Ļ�����
��������������57�ˣ�����2334�����̲�ʵ�����ǵĶ�̬��.*/
#include <iostream>

class CMyString
{
public:
    char m_pString[100] = "abc";
public:
    CMyString* stringcat(CMyString *pString) 
    {
        strcat(m_pString+strlen(m_pString), pString->m_pString);
        return (CMyString*)0;
    }
    virtual CMyString* stringcat(int iAdd1, int iAdd2) 
    { 
        return (CMyString*)0; 
    }
};

class CMyNumString : public CMyString
{
public:
    CMyString* stringcat(int iAdd1, int iAdd2) 
    {
        
        char tmpString[100];
        
        _itoa_s(iAdd1+ iAdd2, tmpString, 10);
        strcpy(m_pString, tmpString);
        return (CMyString*)0;
    }
};

int main()
{
    CMyString str;
    CMyString str1;
    CMyNumString ns1;


    str.stringcat(&str1);
    ((CMyString*)&ns1)->stringcat(12,34);


    std::cout << str.m_pString << std::endl;
    std::cout << ns1.m_pString << std::endl;
    return 0;
}