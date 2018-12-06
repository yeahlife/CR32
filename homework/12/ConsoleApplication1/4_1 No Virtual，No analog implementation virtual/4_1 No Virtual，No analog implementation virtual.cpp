/*
4.编写例子，结合内存的实际布局来说明虚函数的原理。
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

