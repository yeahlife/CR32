/*
1.
场景：
3种兵种：
步兵， 骑兵 ，火枪手

（1） 用virtual 关键字来实现攻击的多态。
（2） 不用virtual 关键字来实现攻击的多态。
*/
#include "stdafx.h"
#include "Arms.h"
#include "Infantry.h"
#include "Cavalry.h"
#include "Gunner.h"

int main()
{
    /*方式1*/
    /*CArms arms;
    CInfantry infantry;
    CCavalry cavalry;
    CGunner gunner;

    arms.attack();
    infantry.attack();
    cavalry.attack();
    gunner.attack();*/

    /*方式2 指针*/
    //CArms arms;
    //CArms *pArms = &arms;
    //CInfantry infantry;
    //CCavalry cavalry;
    //CGunner gunner;

    //pArms->attack(); //Arms

    //pArms = (CArms*)&infantry;
    //pArms->attack(); //Infantry

    //pArms = (CArms*)&cavalry;
    //pArms->attack(); //cavalry

    //pArms = (CArms*)&gunner;
    //pArms->attack(); //gunner

    /*方式3 引用*/
    CArms arms;
    CArms &rarms = arms;
    rarms.attack();//Arms

    CInfantry infantry;
    CInfantry &rinfantry = infantry;
    rinfantry.attack();//Infantry

    CCavalry cavalry;
    CCavalry &rcavalry = cavalry;
    rcavalry.attack();//cavalry

    CGunner gunner;
    CGunner &rgunner = gunner;
    rgunner.attack();//gunner

    return 0;
}

/*
output:
CArms::attack(攻击)
CInfantry::attack(攻击)
CCavalry::attack(攻击)
CGunner::attack(攻击)
*/