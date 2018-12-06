#include "stdafx.h"
#include "Cavalry.h"

PFN_VIRTUAL_CAVALRY CCavalry::m_VirTable[1] = { &CCavalry::attack };

CCavalry::CCavalry()
{
    m_pVirTable = CCavalry::m_VirTable;
}


CCavalry::~CCavalry()
{
}

void CCavalry::attack() {
    printf("CCavalry::attack(¹¥»÷)\r\n");
}
