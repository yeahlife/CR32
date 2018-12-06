/*
���
*/

#include "stdafx.h"
#include <iostream>

class CStudent {
public:
    //���캯��
    CStudent(char* pName, int nGender = 1)
        :m_nGender(nGender) //��ʼ�������б�
    {
        //�����Ƿ��� ���캯��
        std::cout << "CStudent(int nGender)" << std::endl;

        //����ѿռ䣬��������
        m_nName = new char[strlen(pName) + 1];
        //��������
        strcpy_s(m_nName, strlen(pName) + 1, pName);
    }

    //���Խ��ÿ�������
    //CStudent(CStudent& obj) = delete;
    //Ҳ�����Լ�ʵ�ֿ�������
    //���ܵĻ����Ժ͹��캯����һ��
    CStudent(CStudent& obj) //����obj�ͱ�ʾ����CStudent������������
    {
        //�����Ƿ��� ��������
        std::cout << "CStudent(CStudent& obj)" << std::endl;

        //��ʼ�������б���ֵ�ķ�ʽ����Ͳ�����ʹ����
        m_nGender = obj.m_nGender;
        //����ѿռ䣬��������
        m_nName = new char[strlen(obj.m_nName) + 1];
        //��������
        strcpy_s(m_nName, strlen(obj.m_nName) + 1, obj.m_nName);
    }

    //�ǽ������¶��忽�����캯�������У����ֲ�û�дﵽ�����Ŀ��
    //���ﻹ��Ҫ =���������
    CStudent& operator=(CStudent& obj)
    {
        //�����Ƿ��� =���������
        std::cout << "CStudent& operator=(CStudent& obj)" << std::endl;

        //������������
        if (m_nName == obj.m_nName) {
            return *this; //���ص�ǰ�������͵�ָ��
        }
        //�ͷ�����Ķѿռ�
        if (m_nName != NULL) {
            delete[] m_nName;
        }
        m_nName = NULL;
        //��ʼ�������б���ֵ�ķ�ʽ����Ͳ�����ʹ����
        m_nGender = obj.m_nGender;
        //����ѿռ䣬��������
        m_nName = new char[strlen(obj.m_nName) + 1];
        //��������
        strcpy_s(m_nName, strlen(obj.m_nName) + 1, obj.m_nName);
        //��Ҫ����ֵ
        return *this; //���ص�ǰ�������͵�ָ��
    }

    //��������
    ~CStudent()
    {
        //�����Ƿ�������
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
    //CStudent stu2("1");
    //stu2 = stu1;//���� =��������أ��������

    //����һ��CStudent�������Ϊstu2
    //����CStudent��Ĺ��캯��
    CStudent stu2(stu1);//���� �������죬�������

    return 0;
}