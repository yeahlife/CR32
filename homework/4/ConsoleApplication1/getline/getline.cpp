// getline.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream> // std::cin, std::cout

int main()
{
    // 定义两个256字符长度缓冲区，分别接收名字和标题
    char name[256] = { 0 };
    char title[256] = { 0 };

    std::cout << "请输入你的名字： " << std::endl;
    std::cin.getline(name, 256);

    std::cout << "请输入你喜欢的标题：" << std::endl;
    std::cin.getline(title, 256);

    std::cout << name << " 喜爱的标题是 " << title << std::endl;

    return 0;
}

