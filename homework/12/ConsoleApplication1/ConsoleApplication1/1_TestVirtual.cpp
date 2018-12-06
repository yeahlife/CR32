/*
1.
������
3�ֱ��֣�
������ ��� ����ǹ��

��1�� ��virtual �ؼ�����ʵ�ֹ����Ķ�̬��
��2�� ����virtual �ؼ�����ʵ�ֹ����Ķ�̬��
*/
#include "stdafx.h"
#include "Arms.h"
#include "Infantry.h"
#include "Cavalry.h"
#include "Gunner.h"

int main()
{
    /*��ʽ1*/
    /*CArms arms;
    CInfantry infantry;
    CCavalry cavalry;
    CGunner gunner;

    arms.attack();
    infantry.attack();
    cavalry.attack();
    gunner.attack();*/

    /*��ʽ2 ָ��*/
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

    /*��ʽ3 ����*/
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
CArms::attack(����)
CInfantry::attack(����)
CCavalry::attack(����)
CGunner::attack(����)
*/