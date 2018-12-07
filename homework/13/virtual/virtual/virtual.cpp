/*
���в����� ����Ĵ��롣
��Ԥ�Ⲣ˵������ִ�н��,
���Դ�Ϊ�����ܽḲ�ǡ����ء����ص����𣨴�������������ʵ��ԭ�������

�۲�������������ʵ�֣���Ԥ������main�е�ִ�н����
ע�����㣺
1. ���õķ������ĸ�
2. ������ɵ�ԭ�������ء����ǡ������е���һ�֣�
*/

#include "StdAfx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Handle1(float x)
    {
        cout << "Base::Handle1(float) " << x << endl;
    }
    void Handle2(float x)
    {
        cout << "Base::Handle2(float) " << x << endl;
    }
    void Handle3(float x)
    {
        cout << "Base::Handle3(float) " << x << endl;
    }
};

class Derived : public Base
{
public:
    virtual void Handle1(float x)
    {
        cout << "Derived::Handle1(float) " << x << endl;
    }
    void Handle2(int x)
    {
        cout << "Derived::Handle2(int) " << x << endl;
    }
    void Handle3(float x)
    {
        cout << "Derived::Handle3(float) " << x << endl;
    }
    void Handle3(double x)
    {
        cout << "Derived::Handle3(double) " << x << endl;
    }
};


void main(void)
{
    Derived DervObj;
    Base *pBase = &DervObj;
    Derived *pDerv = &DervObj;

    pBase->Handle1(3.14f); //Handle1���麯����pBase��ָ����ã��������ǹ���Derived::Handle1(float) 3.14
    pDerv->Handle1(3.14f); //Handle1���麯����pDerv��ָ����ã��������ǹ���Derived::Handle1(float) 3.14
    cout << endl;

    pBase->Handle2(3.14f); //Handle2����ͨ������ֱ�ӵ��ã��������أ�Base::Handle2(float) 3.14
    pDerv->Handle2(3.14f); //Handle2����ͨ������ֱ�ӵ��ã��������أ�Derived::Handle2(int) 3
    cout << endl;

    pBase->Handle3(3.14f); //Handle3����ͨ������ֱ�ӵ��ã��������أ��������أ�Base::Handle3(float) 3 
    pDerv->Handle3(3.14f); //Handle3����ͨ������ֱ�ӵ��ã��������أ��������أ�Derived::Handle3(float) 3.14
    pDerv->Handle3(3.14);  //Handle3����ͨ������ֱ�ӵ��ã��������أ��������أ�Derived::Handle3(double) 3.14
    cout << endl;

    //pDerv->Handle3(3);
}