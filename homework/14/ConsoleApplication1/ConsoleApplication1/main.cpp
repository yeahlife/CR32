/*
1. ���ؼ̳����麯��

�����Ӽ����������֣�
1. �鿴�����С
2. �����ڴ�ֲ�
3. ��Ա���ù�ϵ
*/

#include "stdafx.h"

class CPerson {
public:
    CPerson() {
        m_p = 0;
    }

    void speak() {
        printf("CPerson::speak(�˻�)\r\n");
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
        printf("CChinese::speak(����)\r\n");
    }

public:
    int m_c;
};

int main()
{
    // �����С
    int nPerSize = sizeof(CPerson);  //4
    int nChsSize = sizeof(CChinese); //8

    // �����ڴ�ֲ�
    CPerson per;
    CChinese chs;

    // ���ù�ϵ
    per.speak();   // ֱ�ӵ���
    chs.speak();   // ֱ�ӵ���

    // ����ת��
    // 1 ����ֵ
    per = chs;
    per.speak();   // ֱ�ӵ���

    // 2 ָ�븳ֵ
    CPerson* pPer = NULL;
    pPer = &chs;
    pPer->speak(); // ֱ�ӵ���

    // 3 ���ø�ֵ
    CPerson &rPer = per;
    rPer = chs;
    rPer.speak();  // ֱ�ӵ���

    return 0;
}

