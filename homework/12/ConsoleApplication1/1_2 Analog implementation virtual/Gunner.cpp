#include "stdafx.h"
#include "Gunner.h"

PFN_VIRTUAL_GUNNER CGunner::m_VirTable[1] = { &CGunner::attack };

CGunner::CGunner()
{
    m_pVirTable = m_VirTable;
}


CGunner::~CGunner()
{
}

void CGunner::attack() {
    printf("CGunner::attack(¹¥»÷)\r\n");
}