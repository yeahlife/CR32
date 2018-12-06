/*
2.
����һ���ǳ��򵥵ġ�shape����Σ�
�����ΪShape��
�������ΪCircle��Square��Triangle��
�ڻ����ֶ���һ���麯��draw()��������Щ���������ض�������
�ڶ��д���Shape���󣬲��ҽ���һ��ָ����ЩShape�����ָ�����飨�������γ���ָ����������ת������
����ͨ������ָ�����draw()��
�����麯������Ϊ��
���������Ըó���
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
CArms::attack(����)
CInfantry::attack(����)
CCavalry::attack(����)
CGunner::attack(����)
*/

