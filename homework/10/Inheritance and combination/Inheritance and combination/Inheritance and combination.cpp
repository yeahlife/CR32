// Inheritance and combination.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<string>
using namespace std;

class CTeacher //老师类
{
public:
private:
    int m_num;
    string m_name;
    char m_sex;
};

class CBirthDate //生日类
{
public:
private:
    int m_year;
    int m_month;
    int m_day;
};


class CProfessor :public CTeacher //教授类
{
public:
private:
    CBirthDate birthday;//BirthDate类的对象作为数据成员
};
/*
 * CProfessor 继承自 CTeacher, is-a
 * CProfessor 与 CBirthDate 组合关系，has-a
 */

int main()
{
    return 0;
}

