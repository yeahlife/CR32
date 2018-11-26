// get.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// istream::get example
#include <iostream> // std::cin, std::cout
#include <fstream>  // std::ifstream

using namespace std;

int main()
{
    // 定义一个256个字符缓冲区
    char str[256];

    std::cout << "Enter the name of an existing text file : " << std::endl;
    std::cin.get(str, 256); // get c-string 接收一个最长256个字符的文件名称

    std::ifstream is(str); // open file 根据用户输入的名字打开文件

    char c;
    while (is.get(c)) // loop getting single characters
    {
        std::cout << c; // 遍历输出文件内容，依次单个字符输出
    }

    is.close(); // close file

    return 0;
}

