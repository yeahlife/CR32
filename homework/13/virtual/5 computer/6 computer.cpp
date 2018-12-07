/*
4. ��Ϊ�������ƶ��ýӿڣ�
ʹ�������Լ��ݷ��ϴ˱�׼�ӿڵ��������������Կ���
(������ʵ�֣���Ӧ�Ľӿڼ�Ϊ����ͳһ��׼��Ϊͳһ����)��
*/
#include "stdafx.h"

class CMotherBoard{//������
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

