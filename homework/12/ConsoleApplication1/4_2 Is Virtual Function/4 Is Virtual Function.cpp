/*
4.��д���ӣ�����ڴ��ʵ�ʲ�����˵���麯����ԭ��
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

//������󣺶�̬-�麯��

class CPerson {
public:
    virtual void Speak() {
        printf("CPerson::Speak()\r\n");
    }

    virtual void Eat() {
        printf("CPerson::Eat()\r\n");
    }
};

class CChinese :public CPerson {
public:    
    void Speak() {
        printf("CChinese::Speak()\r\n");
    }
    void Eat() {
        printf("CChinese::Eat()\r\n");
    }
};

class CEnglish :public CPerson {
public:
    void Speak() {
        printf("CEnglish::Speak()\r\n");
    }
    void Eat() {
        printf("CEnglish::Eat()\r\n");
    }
};

int main()
{
    CPerson per;
    CChinese chs;
    CEnglish eng;

    int nPersonSize = sizeof(CPerson);
    cout << nPersonSize << endl;
    int nChsSize = sizeof(CChinese);
    cout << nChsSize << endl;
    int nEngSize = sizeof(CEnglish);
    cout << nEngSize << endl;

    CPerson* ary[2] = { &chs, &eng };
    for (int i = 0; i < 2; i++) {
        ary[i]->Speak();
    }

    return 0;
}

/*
output:
4
4
4
CChinese::Speak()
CEnglish::Speak()
*/

