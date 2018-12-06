/*
2.
创建一个非常简单的“shape”层次：
基类称为Shape，
派生类称为Circle、Square和Triangle。
在基类种定义一个虚函数draw()，再在这些派生类种重定义它。
在堆中创建Shape对象，并且建立一个指向这些Shape对象的指针数组（这样就形成了指针向上类型转换）。
并且通过基类指针调用draw()，
检验虚函数的行为，
并单步调试该程序。
*/

#include "stdafx.h"
#include "Arms.h"
#include "Infantry.h"
#include "Cavalry.h"
#include "Gunner.h"

int main()
{
    CArms arms;
    CArms* aryArms[1] = { &arms };
    void* pArms = aryArms[0]->m_pVirTable;
    PFN_VIRTUAL pfnArms = *(PFN_VIRTUAL*)pArms;
    (aryArms[0]->*pfnArms)();

    CInfantry infantry;
    CInfantry* aryInfantry[1] = { &infantry };
    void* pInfantry = aryInfantry[0]->m_pVirTable;
    PFN_VIRTUAL_INFANTRY pfnInfantry = *(PFN_VIRTUAL_INFANTRY*)pInfantry;
    (aryInfantry[0]->*pfnInfantry)();

    CCavalry cavalry;
    CCavalry* aryCavalry[1] = { &cavalry };
    void* pCavalry = aryCavalry[0]->m_pVirTable;
    PFN_VIRTUAL_CAVALRY pfnCavalry = *(PFN_VIRTUAL_CAVALRY*)pCavalry;
    (aryCavalry[0]->*pfnCavalry)();

    CGunner gunner;
    CGunner* aryGunner[1] = { &gunner };
    void* pGunner = aryGunner[0]->m_pVirTable;
    PFN_VIRTUAL pfnGunner = *(PFN_VIRTUAL*)pGunner;
    (aryGunner[0]->*pfnGunner)();



    return 0;
}
/*
output:
CArms::attack(攻击)
CInfantry::attack(攻击)
CCavalry::attack(攻击)
CGunner::attack(攻击)
*/

