// rdbuf usage.cpp : 定义控制台应用程序的入口点。
// 利用rdbuf简单复制文件

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // 打开源文件
    fstream fin("test.txt", ios::in|ios::binary);
    if (!fin.is_open())
    {
        std::cout << "源文件打开失败" << std::endl;
        return 0;
    }

    // 打开目的文件
    fstream fout("testcpy.txt", ios::out|ios::binary);
    if (!fout.is_open())
    {
        std::cout << "目的文件打开失败" << std::endl;
        return 0;
    }

    // 将源文件流对象重定向到目的文件流对象
    fout << fin.rdbuf();

    // 关闭文件流
    fin.close();
    fout.close();
}

