// 4. 单重虚继承有虚函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// 家具类
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

// 床类
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

                                  // 向上转型
                                  // 1 基类对象指向派生类对象
    fur = bed;
    fur.sit();   // normal function
    fur.sleep(); // virtual function
                 // 这种方式不会发生虚函数调用，依然是调用各自类中的成员函数。对象赋值对成员对象和this指针无影响。

                 // 2 基类指针指向派生类对象的地址
    CFurniture* pfur = &bed;
    pfur->sit(); // normal function
    pfur->sleep();// virtual function
                  // 由于基类通过指针调用成员函数，而sleep()成员函数同时也是虚函数，这时会发生虚调用，间接调用指针指向的对象的虚函数。

                  // 3 基类指针通过引用指向派生类对象
    CFurniture &rfur = bed;
    rfur.sit(); // normal function
    rfur.sleep(); // virtual function
                  // 由于基类通过引用调用成员函数，而sleep()成员函数同时也是虚函数，发生虚调用，间接调用引用的那个对象的虚函数。

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
请按任意键继续. . .
*/


