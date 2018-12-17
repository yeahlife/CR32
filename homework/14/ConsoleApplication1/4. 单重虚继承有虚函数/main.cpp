// 4. ������̳����麯��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// �Ҿ���
class CFurniture {
public:
    CFurniture() {
        printf("CFurniture::CFurniture()\r\n");
        m_nFurniture = 1;
        m_nFurniture2 = 2;
        m_nFurniture3 = 3;
    }

    ~CFurniture() {
        printf("CFurniture::~CFurniture()\r\n");
        m_nFurniture = 0;
    }

    virtual void sleep() {
        printf("CFurniture::sleep()\r\n");
    }

    void sit() {
        printf("CFurniture::sit()\r\n");
    }

    int m_nFurniture;

protected:
    int m_nFurniture2;

private:
    int m_nFurniture3;
};

// ����
class CBed : virtual public CFurniture {
public:
    CBed() {
        printf("CBed::CBed()\r\n");
        m_nBed = 2;
    }

    ~CBed() {
        printf("CBed::~CBed()\r\n");
        m_nBed = 0;
    }

    virtual void sleep() {
        printf("CBed::sleep()\r\n");
    }

    void sit() {
        printf("CBed::sit()\r\n");
    }

private:
    int m_nBed;
};

int main()
{

    CFurniture fur;
    CBed bed;

    int nSizeFur = sizeof(CFurniture);
    cout << nSizeFur << endl;     // 16
    int nSizeBed = sizeof(CBed);
    cout << nSizeBed << endl;     // 20

                                  // ����ת��
                                  // 1 �������ָ�����������
    fur = bed;
    fur.sit();   // normal function
    fur.sleep(); // virtual function
                 // ���ַ�ʽ���ᷢ���麯�����ã���Ȼ�ǵ��ø������еĳ�Ա����������ֵ�Գ�Ա�����thisָ����Ӱ�졣

                 // 2 ����ָ��ָ�����������ĵ�ַ
    CFurniture* pfur = &bed;
    pfur->sit(); // normal function
    pfur->sleep();// virtual function
                  // ���ڻ���ͨ��ָ����ó�Ա��������sleep()��Ա����ͬʱҲ���麯������ʱ�ᷢ������ã���ӵ���ָ��ָ��Ķ�����麯����

                  // 3 ����ָ��ͨ������ָ�����������
    CFurniture &rfur = bed;
    rfur.sit(); // normal function
    rfur.sleep(); // virtual function
                  // ���ڻ���ͨ�����õ��ó�Ա��������sleep()��Ա����ͬʱҲ���麯������������ã���ӵ������õ��Ǹ�������麯����

    return 0;
}
/*
output:

CFurniture::CFurniture()
CFurniture::CFurniture()
CBed::CBed()
16
20
CFurniture::sit()
CFurniture::sleep()
CFurniture::sit()
CBed::sleep()
CBed::~CBed()
CFurniture::~CFurniture()
CFurniture::~CFurniture()
�밴���������. . .
*/


