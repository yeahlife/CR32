// Test2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyFile.h"

//1. �쳣����Ƕ��
//2. �׳����쳣������ƥ�䣬û����ʽת��
//3. ...��ʾ�������͵��쳣

void Test(){

    try {
        try {
            throw 1.0f;
        }
        catch (int) {
            printf("catch (int)\r\n");
        }
    }
    catch (...) {
        printf("catch (...)\r\n");
    }


}


void foo() {
    CMyFile f;
    try {
        f.Open("123");

    }
    //catch (CMyFileException& e) {
    //    if (e.m_Type == CMyFileException::FILE_EXCPT_OPEN) {
    //        printf("��%s�ļ�ʧ��" , e.what());
    //    }
    //}
    catch (CMyException& e) {
        printf("����%s", e.what());
    }
  
}

int main()
{
    foo();
    //Test();

    return 0;
}

