// read.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// read a file into memory
#include <iostream>     // std::cout, std::cin
#include <fstream>      // std::ifstream

int main() {
    std::ifstream is("test.txt", std::ifstream::binary);//以二进制形式打开文件
    if (is) {
        // get length of file:
        // 获取文件内容长度， tellg() 和 seekg() 接下来会分析，先不管细节
        is.seekg(0, is.end);
        int length = is.tellg();
        is.seekg(0, is.beg);

        // 根据文件内容长度，动态申请堆内存，申请的大小为length长度
        char * buffer = new char[length]; 

        // 这里打印读取到的文件内容长度
        std::cout << "Reading " << length << " characters... ";
        // read data as a block:
        // 然后我们用read函数来读取这个length长度的内容到buffer缓冲区
        // 读取成功返回object(*this)，这应该指的是读取的那个流对象
        is.read(buffer, length);

        if (is)
        {
            // 包括空格，啥的
            std::cout << "all characters read successfully.";
        }   
        else
        {
            // gcount() 统计从流中读取到的字符数
            std::cout << "error: only " << is.gcount() << " could be read";
        }
        // 关闭文件流
        is.close();

        // ...buffer contains the entire file...
        // 释放堆内存
        delete[] buffer;
    }
    return 0;
}

