// getline.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream> // std::cin, std::cout

int main()
{
    // ��������256�ַ����Ȼ��������ֱ�������ֺͱ���
    char name[256] = { 0 };
    char title[256] = { 0 };

    std::cout << "������������֣� " << std::endl;
    std::cin.getline(name, 256);

    std::cout << "��������ϲ���ı��⣺" << std::endl;
    std::cin.getline(title, 256);

    std::cout << name << " ϲ���ı����� " << title << std::endl;

    return 0;
}

