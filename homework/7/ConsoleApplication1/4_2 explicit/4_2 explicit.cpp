// 4_2 explicit.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
4.����˵���ؼ���=default,=delete,explicit�����е����á�
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

class ConverTo {
public:
    explicit ConverTo(int n)
    {
        std::cout << n << std::endl;
    }
};

int main()
{
    // û��ʹ��explicit�ؼ���
    //int n = 10;
    //ConverTo ct(n); // ֱ�ӳ�ʼ����ͨ��
    //ConverTo ct2 = n; // ���������ʼ��������ͨ��
    //ConverTo ct3 = (ConverTo)(n); // ǿ��ת��������ͨ��

    // ʹ��explicit�ؼ���
    int n = 10;
    //ConverTo ct(n); // ֱ�ӳ�ʼ����ͨ��
    //ConverTo ct2 = n; // ���������ʼ�������벻ͨ��
    ConverTo ct3 = (ConverTo)(n); // ǿ��ת��������ͨ��
 
    return 0;
}

/*
explicit �ؼ���
�����������캯��Ϊ��ʽ���죬����һЩ����Ҫ����ʽת����
*/
