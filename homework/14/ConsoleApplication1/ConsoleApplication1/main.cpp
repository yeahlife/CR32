/*
1. 单重继承无虚函数

分析从几个方面入手：
1. 查看对象大小
2. 对象内存分布
3. 成员调用关系
*/

#include "stdafx.h"

class CPerson {
public:
    CPerson() {
        m_p = 0;
    }

    void speak() {
        printf("CPerson::speak(人话)\r\n");
    }

public:
    int m_p;
};

class CChinese:public CPerson {
public:
    CChinese() {
        m_c = 1;
    }

    void speak() {
        printf("CChinese::speak(汉语)\r\n");
    }

public:
    int m_c;
};

int main()
{
    // 对象大小
    int nPerSize = sizeof(CPerson);  //4
    int nChsSize = sizeof(CChinese); //8

    // 对象内存分布
    CPerson per;
    CChinese chs;

    // 调用关系
    per.speak();   // 直接调用
    chs.speak();   // 直接调用

    // 向上转型
    // 1 对象赋值
    per = chs;
    per.speak();   // 直接调用

    // 2 指针赋值
    CPerson* pPer = NULL;
    pPer = &chs;
    pPer->speak(); // 直接调用

    // 3 引用赋值
    CPerson &rPer = per;
    rPer = chs;
    rPer.speak();  // 直接调用

    return 0;
}

