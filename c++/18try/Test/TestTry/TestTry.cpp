// TestTry.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <excpt.h>
#include <DbgHelp.h>

using namespace std;
//�쳣
//��д�쳣�� ��0���ڴ�����ʧ��

//����
 
//void foo() {
//    FILE* fp = fopen("1.txt", "rb");
//    if (fp == NULL) {
//        goto EXIT;
//    }
//
//EXIT:
//    //clear
//}

//void foo_test() {
//    try {
//        FILE* fp = ���ļ�("1.txt", "rb");
//        ���ļ�(fp);
//        �ر��ļ�(fp);
//    }
//    catch (...) {
//        �쳣����;
//    }
//
//}

//�ؼ��֣� try throw catch

void Test() throw(int) {

    //terminate();
    //abort();
    throw 1; 

    //try {
    //    //try�� ҵ���߼�

    //    //throw 1;
    //    //throw ���쳣
    //}
    //catch (int n) {
    //    //catch�� �����쳣
    //    cout << n << endl;
    //}




}

//���׳����쳣���˴���ʱ��ϵͳ�����UEF.



LONG WINAPI myExceptionHandler(
     _EXCEPTION_POINTERS *ExceptionInfo
    )
{
    MessageBox(NULL, _T("�������"), _T("����������������ϵ��������xxx"), NULL);

    cout << hex << ExceptionInfo->ExceptionRecord->ExceptionAddress << endl
         << hex << ExceptionInfo->ContextRecord->Eax << endl;

    HANDLE hFile = CreateFile(_T("1.dmp"),//�ļ���
                             GENERIC_READ | GENERIC_WRITE, //��д��־
                             FILE_SHARE_READ | FILE_SHARE_WRITE,//�����д
                             NULL,//��ȫ����
                             CREATE_NEW,//�����µ�
                             FILE_ATTRIBUTE_NORMAL,//�ļ�����
                             NULL);

    MINIDUMP_EXCEPTION_INFORMATION mei = {0};
    mei.ExceptionPointers = ExceptionInfo;
    mei.ThreadId = GetCurrentThreadId();
    mei.ClientPointers = TRUE;

    BOOL bRet = MiniDumpWriteDump(GetCurrentProcess(),
        GetCurrentProcessId(),
        hFile,
        MiniDumpNormal,
        &mei,
        NULL,
        NULL);

    CloseHandle(hFile);

    return EXCEPTION_EXECUTE_HANDLER;
}

int main()
{
    //�滻Ĭ��UEF��terminate()��
    //SetUnhandledExceptionFilter(myExceptionHandler);
    
    //try {
    //    char* p = NULL;
    //    if (p == NULL) {
    //        throw 1;
    //    } 
    //}
    //catch (...) {
    //    cout << "catch" << endl;
    //}

    //cout << "catch2" << endl;
    
    Test();
    //try {
    //    
    //}
    //catch (int n) {
    //    cout << n << endl;
    //}

    return 0;
}

