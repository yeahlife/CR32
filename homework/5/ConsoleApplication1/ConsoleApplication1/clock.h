#pragma once

// ��ͨ�ĺ���ָ��
typedef int(*PFN_SetTime)(struct tagClock* this, int nH, int nM, int nS);

struct tagClock
{
    //����
    int nHour;
    int nMinute;
    int nSecond;

    //��Ϊ����������
    PFN_SetTime pfn_set;
};

int SetTime(struct tagClock* pClock, int nH, int nM, int nS);
