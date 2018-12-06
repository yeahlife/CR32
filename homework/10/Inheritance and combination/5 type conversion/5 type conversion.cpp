// 5 type conversion.cpp : 定义控制台应用程序的入口点。
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
    /*调用land()方法*/

    /*通过一个SpaceShip对象的指针*/
    SpaceShip *pss = NULL;
    SHuttle *psh = NULL;
    SHuttle sh;
    psh = &sh;
    pss = psh;
    pss->land();

    /*引用向上类型转换*/
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

