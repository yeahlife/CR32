// rdbuf.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
// redirecting cout's output thrrough its stream buffer
#include <iostream>     // std::streambuf, std::cout
#include <fstream>      // std::ofstream

int main() {
    std::streambuf *psbuf, *backup; // �������������󻺳����
    std::ofstream filestr; // �����ļ�������
    filestr.open("test.txt"); // ���ļ�ָ���ļ�������

    backup = std::cout.rdbuf();     // back up cout's streambuf ��cout�����ض���backup������

    psbuf = filestr.rdbuf();        // get file's streambuf ���ļ���filestr�����ض���psbuf������
    std::cout.rdbuf(psbuf);         // assign streambuf to cout ��psbuf�������ض���cout������

    std::cout << "This is written to the file"; // cout�������������ʱcout��������ָ��filestr��Ҳ����˵������ݻᱻд���ļ���

    std::cout.rdbuf(backup);        // restore cout's original streambuf �ָ�cout������

    filestr.close(); // �ر�filestr�ļ���

    return 0;
}
