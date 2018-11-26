// tellg.cpp : �������̨Ӧ�ó������ڵ㡣
//

// ���� ��tellg() �� seekg() һ��������

#include "stdafx.h"
// read a file into memory
#include <iostream> // std::cout, std::cin
#include <fstream> // std::ifstream

int main()
{
    // �����ƴ��ļ�
    std::ifstream is("test.txt", std::ifstream::binary);

    if (is)
    {
        // get length of file:
        is.seekg(0, is.end); // ���ļ�ָ��ָ���ļ�ĩβ������C�����е�fseek������
        int length = is.tellg(); // �õ���ǰ�ַ������������е�λ�ã�Ҳ�����ļ����ݵĳ���
        is.seekg(0, is.beg); // ���ļ�ָ������ָ���ļ���ʼ��λ��

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

