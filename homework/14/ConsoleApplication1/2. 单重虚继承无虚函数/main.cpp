// 2. 单重虚继承无虚函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// 家具类
class CFurniture {
public:
    CFurniture() {
        printf("CFurniture::CFurniture()\r\n");
        m_nFurniture = 3;
        //m_nFurniture2 = 4;
    }

    ~CFurniture() {
        printf("CFurniture::~CFurniture()\r\n");
        m_nFurniture = 0;
    }

    int m_nFurniture;
    //int m_nFurniture2;
};

// 沙发类，虚继承
class CSofa :virtual public CFurniture {
public:
    CSofa() {
        printf("CSofa::CSofa()\r\n");
        m_nSofa = 1;
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

// 床类，虚继承
class CBed :virtual public CFurniture {
public:
    CBed() {
        printf("CBed::CBed()\r\n");
        m_nBed = 2;
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

int main()
{
    // 实例化对象
    CFurniture furniture;
    CSofa sofa;
    CBed bed;

    // 对象大小
    int nSizeFurniture = sizeof(CFurniture);
    cout << nSizeFurniture << endl; // 4
    int nSizeSofa = sizeof(CSofa);
    cout << nSizeSofa << endl;      // 12
    int nSizeBed = sizeof(bed);
    cout << nSizeBed << endl;       // 12

    return 0;
}

