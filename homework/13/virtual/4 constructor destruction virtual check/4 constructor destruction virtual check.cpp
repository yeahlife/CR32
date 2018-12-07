/*
1. ����˵�����캯�������������е����麯���Ƿ�������ã�Ϊʲô��
*/

#include "stdafx.h"

class CPerson {
public:
    CPerson() {
        Test(); //call CPerson::Test
    }

    virtual ~CPerson() {
        printf("~CPerson");
        Test(); //call CPerson::Test
    }

    virtual void Speak() {
        printf("CPerson::Speak(�˻�)\r\n");
    }

    virtual void Eat() {
        printf("CPerson::Eat(����)\r\n");
    }

    //virtual void Test() {
    virtual void Test() {
        this->Speak(); //���thisȡ���ڵ��÷�ָ��Ķ���
    }
};

class CChinese :public CPerson {
public:
    CChinese() {
        Test();//call CChinese::Test
    }

    virtual ~CChinese() {
        printf("~CChinese");
        Test();//call CChinese::Test
    }

    virtual void Eat() {
        printf("CChinese::Eat(�в�)\r\n");
    }

    virtual void Speak() {
        printf("CChinese::Speak(����)\r\n");
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
//��������ԭ��
// delete �����ָ��ʱ�������ж�̬���ܹ����õ�����������������
/*
CPerson::Speak(�˻�)
CChinese::Speak(����)
CChinese::Speak(����)
~CChineseCChinese::Speak(����)
~CPersonCPerson::Speak(�˻�)
*/

