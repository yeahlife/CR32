// The Copy Constructor.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
ǳ����
*/

#include "stdafx.h"
#include <iostream>

class CStudent {
public:
    //���캯��
    CStudent(char* pName, int nGender = 1)
        :m_nGender(nGender) //��ʼ�������б�
    {
        //����ѿռ䣬��������
        m_nName = new char[strlen(pName) + 1];
        //��������
        strcpy_s(m_nName, strlen(pName) + 1, pName);
        std::cout << "CStudent(int nGender)" << std::endl;
    }
    //��������
    ~CStudent()
    {
        std::cout << "~CStudent()" << std::endl;
        //�ͷ�����Ķѿռ�
        if (m_nName != NULL) {
            delete[] m_nName;
        }
        m_nName = NULL;
    }

private:
    int m_nGender; //�Ա�
    char* m_nName; //����
};

int main()
{
    char szName[] = "zhangsan";
    //����һ��CStudent�������Ϊstu1
    //����CStudent��Ĺ��캯��
    CStudent stu1(szName, 1);
    //����һ��CStudent�������Ϊstu2
    //����CStudent��Ĺ��캯��
    CStudent stu2("1"); 
    //��stu1���󿽱���stu2����
    stu2 = stu1;

    return 0;
}

