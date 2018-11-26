// read.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
// read a file into memory
#include <iostream>     // std::cout, std::cin
#include <fstream>      // std::ifstream

int main() {
    std::ifstream is("test.txt", std::ifstream::binary);//�Զ�������ʽ���ļ�
    if (is) {
        // get length of file:
        // ��ȡ�ļ����ݳ��ȣ� tellg() �� seekg() ��������������Ȳ���ϸ��
        is.seekg(0, is.end);
        int length = is.tellg();
        is.seekg(0, is.beg);

        // �����ļ����ݳ��ȣ���̬������ڴ棬����Ĵ�СΪlength����
        char * buffer = new char[length]; 

        // �����ӡ��ȡ�����ļ����ݳ���
        std::cout << "Reading " << length << " characters... ";
        // read data as a block:
        // Ȼ��������read��������ȡ���length���ȵ����ݵ�buffer������
        // ��ȡ�ɹ�����object(*this)����Ӧ��ָ���Ƕ�ȡ���Ǹ�������
        is.read(buffer, length);

        if (is)
        {
            // �����ո�ɶ��
            std::cout << "all characters read successfully.";
        }   
        else
        {
            // gcount() ͳ�ƴ����ж�ȡ�����ַ���
            std::cout << "error: only " << is.gcount() << " could be read";
        }
        // �ر��ļ���
        is.close();

        // ...buffer contains the entire file...
        // �ͷŶ��ڴ�
        delete[] buffer;
    }
    return 0;
}

