// Inheritance and combination.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include<string>
using namespace std;

class CTeacher //��ʦ��
{
public:
private:
    int m_num;
    string m_name;
    char m_sex;
};

class CBirthDate //������
{
public:
private:
    int m_year;
    int m_month;
    int m_day;
};


class CProfessor :public CTeacher //������
{
public:
private:
    CBirthDate birthday;//BirthDate��Ķ�����Ϊ���ݳ�Ա
};
/*
 * CProfessor �̳��� CTeacher, is-a
 * CProfessor �� CBirthDate ��Ϲ�ϵ��has-a
 */

int main()
{
    return 0;
}

