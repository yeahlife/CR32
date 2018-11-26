#include "stdafx.h"

typedef int(*PFN_SetTime)(struct tagClock* this, int nH, int nM, int nS);

struct tagClock {
    //数据
    int nHour;
    int nMinute;
    int nSecond;

    PFN_SetTime pfn_set;
};

//行为
int SetTime(struct tagClock* pClock, int nH, int nM, int nS) {
    pClock->nHour = nH;
    pClock->nMinute = nM;
    pClock->nSecond = nS;

    return 0;
}

int main()
{
    struct tagClock cl;
    // 第1种修改属性值的形式
    cl.nHour = 25;
    cl.nMinute = 50;
    // 第2种修改属性值的形式，利用函数指针
    cl.pfn_set = SetTime;
    cl.pfn_set(&cl, 1, 2, 3);

    return 0;
}

