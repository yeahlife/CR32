// rdbuf usage.cpp : �������̨Ӧ�ó������ڵ㡣
// ����rdbuf�򵥸����ļ�

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // ��Դ�ļ�
    fstream fin("test.txt", ios::in|ios::binary);
    if (!fin.is_open())
    {
        std::cout << "Դ�ļ���ʧ��" << std::endl;
        return 0;
    }

    // ��Ŀ���ļ�
    fstream fout("testcpy.txt", ios::out|ios::binary);
    if (!fout.is_open())
    {
        std::cout << "Ŀ���ļ���ʧ��" << std::endl;
        return 0;
    }

    // ��Դ�ļ��������ض���Ŀ���ļ�������
    fout << fin.rdbuf();

    // �ر��ļ���
    fin.close();
    fout.close();
}

