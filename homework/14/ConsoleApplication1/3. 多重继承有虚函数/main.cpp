// 3. 多重继承有虚函数.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
using namespace std;

// 床类
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

    virtual void sleep() {
        printf("CBed::sleep()\r\n");
    }

    void sleep2() {
        printf("CBed::sleep2()\r\n");
    }

private:
    int m_nBed;
};

// 沙发类
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

    virtual void sit() {
        printf("CSofa::sit()\r\n");
    }

    void sit2() {
        printf("CSofa::sit2()\r\n");
    }

private:
    int m_nSofa;
};

// 沙发床多重继承，既继承了沙发的特点，又继承了床的特点。
class CSofaBed : public CSofa, public CBed {
public:
    CSofaBed() {
        printf("CSofaBed::CSofaBed()\r\n");
        m_nSofaBed = 3;
    }

    virtual void sleep() {
        printf("CSofaBed::sleep()\r\n");
    }

    virtual void sit() {
        printf("CSofaBed::sit()\r\n");
    }

    void test() {
        printf("CSofaBed::test()\r\n");
    }

private:
    int m_nSofaBed;
};

int main()
{
    CSofa sofa;
    CBed bed;
    CSofaBed sofabed;
    //对象大小
    cout << sizeof(CSofa) << endl;   // 8
    cout << sizeof(CBed) << endl;    // 8
    cout << sizeof(sofabed) << endl; // 20
}
