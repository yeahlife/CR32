// 5 type conversion.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class SpaceShip
{
public:
    void fly();
    void land();
};

class SHuttle:public SpaceShip
{
public:
    void land();
};

void SpaceShip::fly()
{
    cout << "SpaceShip fly()" << endl;
}

void SpaceShip::land()
{
    cout << "SpaceShip land()" << endl;
}

void SHuttle::land()
{
    cout << "SHuttle land()" << endl;
}

int main()
{
    /*����land()����*/

    /*ͨ��һ��SpaceShip�����ָ��*/
    SpaceShip *pss = NULL;
    SHuttle *psh = NULL;
    SHuttle sh;
    psh = &sh;
    pss = psh;
    pss->land();

    /*������������ת��*/
    SpaceShip ss;
    SpaceShip &rss= ss;
    //SHuttle sh;
    rss = sh;
    rss.land();


    return 0;
}
/*
output:

SpaceShip land()
*/

