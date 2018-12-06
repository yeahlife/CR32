#pragma once
#include "Arms.h"
class CGunner :
    public CArms
{
public:
    CGunner();
    ~CGunner();

    //virtual void attack();
    void attack();
    static PFN_VIRTUAL_GUNNER m_VirTable[1];
};

