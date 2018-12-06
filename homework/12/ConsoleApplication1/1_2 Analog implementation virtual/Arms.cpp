#include "stdafx.h"
#include "Arms.h"

PFN_VIRTUAL CArms::m_VirTable[1] = {&CArms::attack};

CArms::CArms()
{
    m_pVirTable = m_VirTable;
}


CArms::~CArms()
{
}

void CArms::attack()
{
    printf("CArms::attack(¹¥»÷)\r\n");
}
