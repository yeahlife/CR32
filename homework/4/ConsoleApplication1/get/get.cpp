// get.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
// istream::get example
#include <iostream> // std::cin, std::cout
#include <fstream>  // std::ifstream

using namespace std;

int main()
{
    // ����һ��256���ַ�������
    char str[256];

    std::cout << "Enter the name of an existing text file : " << std::endl;
    std::cin.get(str, 256); // get c-string ����һ���256���ַ����ļ�����

    std::ifstream is(str); // open file �����û���������ִ��ļ�

    char c;
    while (is.get(c)) // loop getting single characters
    {
        std::cout << c; // ��������ļ����ݣ����ε����ַ����
    }

    is.close(); // close file

    return 0;
}

