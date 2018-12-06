#include "stdafx.h"
#include "Infantry.h"

PFN_VIRTUAL_INFANTRY CInfantry::m_VirTable[1] = { &CInfantry::attack };

CInfantry::CInfantry()
{
    m_pVirTable = m_VirTable;
}


CInfantry::~CInfantry()
{
}

void CInfantry::attack() {
    printf("CInfantry::attack(¹¥»÷)\r\n");
}
