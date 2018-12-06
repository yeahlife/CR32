#pragma once
#include "Arms.h"
class CCavalry :
    public CArms
{
public:
    CCavalry();
    ~CCavalry();

    //virtual void attack();
    void attack();
    static PFN_VIRTUAL_CAVALRY m_VirTable[1];
};

