/*
    ����һ�����е�һ���Ͳ�������ģ�壬��������ΪBob��
    ʹBob��Ϊһ����ΪFriendly��ģ���������ʵ������Ԫ��
    ���ҳ�Ϊһ����ΪPicky����ģ�����Ԫ��������Bob��Picky�����Ͳ�����ȫ��ͬ��ʱ��
    �ṩһЩ��֤����Щ�����Ԫ��ϵ��Bob��Ա������
*/

#include "StdAfx.h"
#include <stdlib.h>
#include <iostream>

template<typename T>
class CBob
{
public:
};

template<typename T>
class CFriendly
{
    CFriendly()
    {
        m_nNum = 0;
    }
public:
    friend CBob;
private:
    int m_nNum;
};

template<typename T>
class CPicky
{
public:
};

int main(void)
{

    system("pause");
    return 0;
}







