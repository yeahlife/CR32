// rdbuf.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// redirecting cout's output thrrough its stream buffer
#include <iostream>     // std::streambuf, std::cout
#include <fstream>      // std::ofstream

int main() {
    std::streambuf *psbuf, *backup; // 定义两个流对象缓冲对象
    std::ofstream filestr; // 定义文件流对象
    filestr.open("test.txt"); // 打开文件指向文件流对象

    backup = std::cout.rdbuf();     // back up cout's streambuf 将cout对象重定向到backup流对象

    psbuf = filestr.rdbuf();        // get file's streambuf 将文件流filestr对象重定向到psbuf流对象
    std::cout.rdbuf(psbuf);         // assign streambuf to cout 把psbuf流对象重定向到cout流对象

    std::cout << "This is written to the file"; // cout流对象输出，此时cout流对象是指的filestr，也就是说这段内容会被写到文件中

    std::cout.rdbuf(backup);        // restore cout's original streambuf 恢复cout流对象

    filestr.close(); // 关闭filestr文件流

    return 0;
}
