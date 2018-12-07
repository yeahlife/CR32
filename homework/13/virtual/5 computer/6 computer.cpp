/*
4. 请为主板类制定好接口，
使得它可以兼容符合此标准接口的声卡，网卡，显卡等
(都用类实现，相应的接口即为函数统一标准即为统一函数)。
*/
#include "stdafx.h"

class CMotherBoard{//主板类
public:
    virtual void MyAudioCard() = NULL;
    virtual void MyNetworkInterfaceCard() = NULL;
    virtual void MyGraphicsCard() = NULL;
};


class CAudioCard :public CMotherBoard {
public:
    virtual void MyAudioCard() {
        printf("CAudioCard::MyAudioCard()\r\n");
    }
    virtual void MyNetworkInterfaceCard() {};
    virtual void MyGraphicsCard() {};
};

class CNetworkInterfaceCard :public CMotherBoard {
public:
    virtual void MyNetworkInterfaceCard() {
        printf("CNetworkInterfaceCard::MyNetworkInterfaceCard()\r\n");
    }
    virtual void MyAudioCard() {};
    virtual void MyGraphicsCard() {};
};

class CGraphicsCard :public CMotherBoard {
public:
    virtual void MyGraphicsCard() {
        printf("CGraphicsCard::MyGraphicsCard()\r\n");
    }
    virtual void MyAudioCard() {};
    virtual void MyNetworkInterfaceCard() {};
};

int main()
{
    CMotherBoard* pMtb = NULL;

    //audioCard
    pMtb = new CAudioCard();
    pMtb->MyAudioCard();
    pMtb = new CNetworkInterfaceCard();
    pMtb->MyNetworkInterfaceCard();
    pMtb = new CGraphicsCard();
    pMtb->MyGraphicsCard();
    

    return 0;
}

void CMotherBoard::MyAudioCard()
{
}

void CMotherBoard::MyNetworkInterfaceCard()
{
}

void CMotherBoard::MyGraphicsCard()
{
}

