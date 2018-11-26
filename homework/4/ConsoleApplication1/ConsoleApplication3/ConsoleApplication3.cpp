// ConsoleApplication3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//����� IMP_MYPRINT(type)
#define IMP_MYPRINT(type) void myPrint(type arg) \
                            {\
                                printf("myPrint("#type")\r\n");\
                            }

//��������ԭ��
IMP_MYPRINT(char);
IMP_MYPRINT(int);
IMP_MYPRINT(unsigned char);
IMP_MYPRINT(double);
IMP_MYPRINT(float);
IMP_MYPRINT(long);
IMP_MYPRINT(int *);
IMP_MYPRINT(const char*);
IMP_MYPRINT(char*);
IMP_MYPRINT(void *);

int main(int argc, char* argv[])
{
    /* code inserted here */
    const char* strHello = "hello";
    myPrint(strHello); // IMP_MYPRINT(const char*);

    myPrint(49); // IMP_MYPRINT(int);

    myPrint('c'); // IMP_MYPRINT(char);

    myPrint(0); // IMP_MYPRINT(int);

    myPrint(NULL); // IMP_MYPRINT(int *); ==> IMP_MYPRINT(int);

    myPrint("hello"); // IMP_MYPRINT(char*); ==> IMP_MYPRINT(const char*);

    myPrint(2.5); // IMP_MYPRINT(double); 

    myPrint(2.5f); // IMP_MYPRINT(float);

    myPrint(argc); // IMP_MYPRINT(int);

    void *pVoid = NULL;
    myPrint(pVoid); // IMP_MYPRINT(void *);

    return 0;
}

/*
��������ʱ��ƥ����ɣ�
���ݷ���ֵ���ͣ�����Լ������������������˳��ƥ�䣬
��ƥ����ȷ��ʹ�á�
������һЩ��������������������ض�������������塣
*/
