/*
举例说明为什么析构函数通常都是虚函数？
*/

#include "stdafx.h"

class CPerson {
public:
    CPerson() {
        Test();
    }

    virtual ~CPerson() {
        printf("~CPerson");
        Test();
    }

    virtual void Speak() {
        printf("CPerson::Speak(人话)\r\n");
    }

    virtual void Eat() {
        printf("CPerson::Eat(东西)\r\n");
    }

    //virtual void Test() {
    virtual void Test() {
        this->Speak(); //这个this取决于调用方指向的对象
    }
};

class CChinese :public CPerson {
public:
    CChinese() {
        Test();
    }

    virtual ~CChinese() {
        printf("~CChinese");
        Test();
    }

    virtual void Eat() {
        printf("CChinese::Eat(中餐)\r\n");
    }

    virtual void Speak() {
        printf("CChinese::Speak(汉语)\r\n");
    }

    //virtual void Test() {
    //    this->Speak();
    //}
};

int main()
{
    CPerson* pPer = new CChinese();
    
    pPer->Test();//Test virtual function, pPer pointer call, function coverage

    delete pPer;// delete CChinese

    return 0;
}
//虚析构的原因：
// delete 类对象指针时，可以有多态，能够调用到子类对象的析构函数
/*
CPerson::Speak(人话)
CChinese::Speak(汉语)
CChinese::Speak(汉语)
~CChineseCChinese::Speak(汉语)
~CPersonCPerson::Speak(人话)
*/

