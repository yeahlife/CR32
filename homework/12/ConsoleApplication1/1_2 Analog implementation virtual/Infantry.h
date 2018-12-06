#pragma once
#include "Arms.h"
class CInfantry :
    public CArms
{
public:
    CInfantry();
    ~CInfantry();

    //virtual void attack();
    void attack();
    static PFN_VIRTUAL_INFANTRY m_VirTable[1];
};

