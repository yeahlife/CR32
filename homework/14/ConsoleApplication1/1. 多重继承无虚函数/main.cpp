// 1. ���ؼ̳����麯��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// ����
class CBed {
public:
    CBed() {
        printf("CBed::CBed()\r\n");
        m_nBed = 1;
    }

    ~CBed() {
        printf("CBed::~CBed()\r\n");
        m_nBed = 0;
    }

    void sleep() {
        printf("CBed::sleep()\r\n");
    }

private:
    int m_nBed;
};

// ɳ����
class CSofa {
public:
    CSofa() {
        printf("CSofa::CSofa()\r\n");
        m_nSofa = 2;
    }

    ~CSofa() {
        printf("CSofa::~CSofa()\r\n");
        m_nSofa = 0;
    }

    void sit() {
        printf("CSofa::sit()\r\n");
    }

private:
    int m_nSofa;
};

// ɳ�������ؼ̳У��ȼ̳���ɳ�����ص㣬�ּ̳��˴����ص㡣
class CSofaBed : public CSofa, public CBed {
public:
    CSofaBed() {
        printf("CSofaBed::CSofaBed()\r\n");
        m_nSofaBed = 3;
    }
    
private:
    int m_nSofaBed;
};

int main()
{
    CSofa sofa;
    CBed bed;
    CSofaBed sofabed;
    //�����С
    cout << sizeof(CSofa) << endl;   // 4
    cout << sizeof(CBed) << endl;    // 4
    cout << sizeof(sofabed) << endl; // 12
}
/*
output:

CSofa::CSofa()
CBed::CBed()
CSofa::CSofa()
CBed::CBed()
CSofaBed::CSofaBed()
4
4
12
CBed::~CBed()
CSofa::~CSofa()
CBed::~CBed()
CSofa::~CSofa()
*/


