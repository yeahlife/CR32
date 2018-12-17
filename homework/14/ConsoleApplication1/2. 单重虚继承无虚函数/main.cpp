// 2. ������̳����麯��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// �Ҿ���
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

// ɳ���࣬��̳�
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

// ���࣬��̳�
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
    // ʵ��������
    CFurniture furniture;
    CSofa sofa;
    CBed bed;

    // �����С
    int nSizeFurniture = sizeof(CFurniture);
    cout << nSizeFurniture << endl; // 4
    int nSizeSofa = sizeof(CSofa);
    cout << nSizeSofa << endl;      // 12
    int nSizeBed = sizeof(bed);
    cout << nSizeBed << endl;       // 12

    return 0;
}

