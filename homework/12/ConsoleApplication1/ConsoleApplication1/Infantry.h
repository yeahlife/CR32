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
};

