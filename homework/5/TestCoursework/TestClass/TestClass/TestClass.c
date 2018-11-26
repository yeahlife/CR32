#include "stdafx.h"

typedef int(*PFN_SetTime)(struct tagClock* this, int nH, int nM, int nS);

struct tagClock {
    //����
    int nHour;
    int nMinute;
    int nSecond;

    PFN_SetTime pfn_set;
};

//��Ϊ
int SetTime(struct tagClock* pClock, int nH, int nM, int nS) {
    pClock->nHour = nH;
    pClock->nMinute = nM;
    pClock->nSecond = nS;

    return 0;
}

int main()
{
    struct tagClock cl;
    // ��1���޸�����ֵ����ʽ
    cl.nHour = 25;
    cl.nMinute = 50;
    // ��2���޸�����ֵ����ʽ�����ú���ָ��
    cl.pfn_set = SetTime;
    cl.pfn_set(&cl, 1, 2, 3);

    return 0;
}

