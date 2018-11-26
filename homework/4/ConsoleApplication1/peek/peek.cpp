// peek.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
// istream::peek example
#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit

int main() {

    std::cout << "Please, enter a number or a word: ";
    std::cout.flush();    // ensure output is written ����֮ǰ�������������

    std::cin >> std::ws;  // eat up any leading white spaces ��տհ�
    int c = std::cin.peek();  // peek character ����һ��char���ַ�
    std::cout << c << std::endl;

    if (c == EOF) return 1; // �ڵ����ڼ��Ѿ������þͷ���EOF
    if (std::isdigit(c))
    {
        int n; // ����һ�����ͳ�����cin�������д�뵽n
        std::cin >> n;
        std::cout << "You entered the number: " << n << '\n';
    }
    else
    {
        std::string str; // ����һ���ַ���������cin�������д�뵽str
        std::cin >> str;
        std::cout << "You entered the word: " << str << '\n';
    }

    return 0;
}

/*
output:
1 49
ireow 105

ASCII����Ӧ��ϵ

ASCII Symbol
49    1
105   i
*/