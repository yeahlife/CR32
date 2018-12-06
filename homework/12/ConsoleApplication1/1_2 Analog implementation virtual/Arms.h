#pragma once

class CArms;
typedef void(CArms::*PFN_VIRTUAL)(void);
class CInfantry;
typedef void(CInfantry::*PFN_VIRTUAL_INFANTRY)(void);
class CCavalry;
typedef void(CCavalry::*PFN_VIRTUAL_CAVALRY)(void);
class CGunner;
typedef void(CGunner::*PFN_VIRTUAL_GUNNER)(void);


class CArms
{
public:
    CArms();
    ~CArms();

    void attack();

public:
    static PFN_VIRTUAL m_VirTable[1];
    void* m_pVirTable;
};

