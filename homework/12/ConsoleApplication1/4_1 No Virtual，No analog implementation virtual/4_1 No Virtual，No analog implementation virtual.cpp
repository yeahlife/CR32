/*
4.��д���ӣ�����ڴ��ʵ�ʲ�����˵���麯����ԭ��
*/

#include "stdafx.h"

class CPerson {
    void Speak() {
        printf("CPerson::Speak()\r\n");
    }
};

class CChinese :public CPerson {
    void Speak() {
        printf("CChinese::Speak()\r\n");
    }
};

class CEnglist :public CPerson {
    void Speak() {
        printf("CEnglist::Speak()\r\n");
    }
};

int main()
{

    return 0;
}

