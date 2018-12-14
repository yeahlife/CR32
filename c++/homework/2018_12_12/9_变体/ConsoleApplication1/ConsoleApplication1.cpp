/*
��дһ�����е�һ���Ͳ�����T)�ĺ���ģ�壬
��������4������������
һ��T�����飬
һ����ʼ����ֵ��
ָ������Ĵ���Ϊʲô�޷����룿
*/

#include "StdAfx.h"
#include <stdlib.h>
#include <iostream>

class CVarient
{
public:
    enum VT_TYPE
    {
        VT_INT,
        VT_FLOAT,
        VT_STR
    };

    int operator= (int n)
    {
        m_Type = VT_INT;
        m_Var.m_nInt = n;
        return n;
    }

    float operator= (float f)
    {
        m_Type = VT_FLOAT;
        m_Var.m_float = f;
        return f;
    }

    char* operator= (char* pSz)
    {
        m_Type = VT_STR;
        m_Var.m_pStr = pSz;
        return pSz;
    }

    friend std::ostream& operator<<(std::ostream& cout, CVarient& obj);

private:
    union m_Union
    {
        int   m_nInt;
        float m_float;
        char *m_pStr;
    };
    VT_TYPE m_Type;
    m_Union m_Var;
};

std::ostream& operator<<(std::ostream& cout, CVarient& obj)
{

    if (CVarient::VT_INT == obj.m_Type)
    {
        std::cout << obj.m_Var.m_nInt;
    }
    else if (CVarient::VT_FLOAT == obj.m_Type)
    {
        std::cout << obj.m_Var.m_float;
    }
    else if (CVarient::VT_STR == obj.m_Type)
    {
        std::cout << obj.m_Var.m_pStr;
    }

    return cout;
}

int main()
{
    CVarient Var;

    Var = 123;
    std::cout << Var << std::endl;

    Var = 12.3f;
    std::cout << Var << std::endl;


    Var = "Test";
    std::cout << Var << std::endl;
    system("pause");
    return 0;
}


