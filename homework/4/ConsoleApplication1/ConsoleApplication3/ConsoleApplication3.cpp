// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//定义宏 IMP_MYPRINT(type)
#define IMP_MYPRINT(type) void myPrint(type arg) \
                            {\
                                printf("myPrint("#type")\r\n");\
                            }

//声明函数原型
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
函数重载时的匹配规律：
根据返回值类型，调用约定，参数个数，参数顺序匹配，
先匹配先确定使用。
等其他一些不满足编译的情况定义在特定情况下属错误定义。
*/
