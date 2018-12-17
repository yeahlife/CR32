// 2. 多重虚继承无虚函数.cpp : 定义控制台应用程序的入口点。
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

    void sleep() {
        printf("CBed::sleep()\r\n");
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

    void sit() {
        printf("CSofa::sit()\r\n");
    }

private:
    int m_nSofa;
};

// 沙发床多重继承，既继承了沙发的特点(虚继承)，又继承了床的特点。
class CSofaBed : virtual public CSofa, public CBed {
public:
    CSofaBed() {
        printf("CSofaBed::CSofaBed()\r\n");
        m_nSofaBed = 3;
    }

private:
    int m_nSofaBed;
};

// 沙发床多重继承，既继承了沙发的特点(虚继承)，又继承了床的特点。(虚继承)
class CSofaBed2 : virtual public CSofa, virtual public CBed {
public:
    CSofaBed2() {
        printf("CSofaBed::CSofaBed2()\r\n");
        m_nSofaBed = 4;
    }

private:
    int m_nSofaBed;
};

int main()
{
    CSofa sofa;
    CBed bed;
    CSofaBed sofabed;
    CSofaBed2 sofabed2;
    //对象大小
    cout << sizeof(CSofa) << endl;   // 4
    cout << sizeof(CBed) << endl;    // 4
    cout << sizeof(sofabed) << endl; // 16
    cout << sizeof(sofabed2) << endl;// 16
}
/*
output:

CSofa::CSofa()
CBed::CBed()
CSofa::CSofa()
CBed::CBed()
CSofaBed::CSofaBed()
CSofa::CSofa()
CBed::CBed()
CSofaBed::CSofaBed2()
4
4
16
16
CBed::~CBed()
CSofa::~CSofa()
CBed::~CBed()
CSofa::~CSofa()
CBed::~CBed()
CSofa::~CSofa()
*/


