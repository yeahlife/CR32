// peek.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// istream::peek example
#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit

int main() {

    std::cout << "Please, enter a number or a word: ";
    std::cout.flush();    // ensure output is written 忽略之前输出缓冲区内容

    std::cin >> std::ws;  // eat up any leading white spaces 清空空白
    int c = std::cin.peek();  // peek character 返回一个char型字符
    std::cout << c << std::endl;

    if (c == EOF) return 1; // 在调用期间已经被设置就返回EOF
    if (std::isdigit(c))
    {
        int n; // 声明一个整型常量，cin会把数据写入到n
        std::cin >> n;
        std::cout << "You entered the number: " << n << '\n';
    }
    else
    {
        std::string str; // 声明一个字符串常量，cin会把数据写入到str
        std::cin >> str;
        std::cout << "You entered the word: " << str << '\n';
    }

    return 0;
}

/*
output:
1 49
ireow 105

ASCII码表对应关系

ASCII Symbol
49    1
105   i
*/