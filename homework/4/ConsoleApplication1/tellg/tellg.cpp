// tellg.cpp : 定义控制台应用程序的入口点。
//

// 这里 把tellg() 和 seekg() 一起来分析

#include "stdafx.h"
// read a file into memory
#include <iostream> // std::cout, std::cin
#include <fstream> // std::ifstream

int main()
{
    // 二进制打开文件
    std::ifstream is("test.txt", std::ifstream::binary);

    if (is)
    {
        // get length of file:
        is.seekg(0, is.end); // 将文件指针指向文件末尾，类型C语言中的fseek的作用
        int length = is.tellg(); // 得到当前字符在输入序列中的位置，也就是文件内容的长度
        is.seekg(0, is.beg); // 将文件指针重新指向文件开始的位置

        // allocate memory:
        char * buffer = new char[length];

        // read data as a block
        is.read(buffer, length);

        is.close();

        // printf content:
        std::cout.write(buffer, length);

        // destory memory:
        delete[] buffer;
    }
    return 0;
}

