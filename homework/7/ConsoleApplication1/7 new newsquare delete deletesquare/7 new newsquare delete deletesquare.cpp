// 7 new newsquare delete deletesquare.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class CTest {
public:
    CTest()
    {
        std::cout << "CTest()" << std::endl;
    }
    ~CTest()
    {
        std::cout << "~CTest()" << std::endl;
    }

    int n;
    float fn;

};

int main()
{
    // ����N��CTest������ڴ�ռ�
    CTest* pTest = new CTest[3];

    //delete pTest; //�쳣
    delete pTest;
    //delete[] pTest;

    return 0;
}
/*
0x00074C76  fd fd fd fd  ????
0x00074C80  03 00 00 00  ....
0x00074C84  cd cd cd cd  ????
0x00074C88  cd cd cd cd  ????
0x00074C8C  cd cd cd cd  ????
0x00074C90  cd cd cd cd  ????
0x00074C94  cd cd cd cd  ????
0x00074C98  cd cd cd cd  ????
0x00074C9C  fd fd fd fd

delete pTest������쳣
�쳣��ԭ��
�ѹ�new CTest[3]�󣬱��������ظ����ǵĶ����ָ��ָ����ڴ��ַ�� 0x00074C84
��������delete[] pTest�ͷ��ڴ��ʱ�򣬱��������Զ�����Ҫ�ͷŵĶ��ڴ档
���ǵ�����ʹ��delete pTest��ʱ�򣬱������ڲ���Ȼ�ᰴ������ģʽȥ���������ڴ�
����������ӵġ�delete (CTest*)((char*)pTest - 4)���Ǽ�����ָ��ָ����ڴ��ַ����0x00074C80��
�ͷţ����յ��¶��ڴ�Ĳ�ƽ�⣬�����쳣��

delete[] pTest�����ͷ��ڴ�
*/