// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "clock.h"

int SetTime(struct tagClock* pClock, int nH, int nM, int nS)
{
    pClock->nHour = nH;
    pClock->nMinute = nM;
    pClock->nSecond = nS;

    return 0;
}

int main()
{
    struct tagClock cl;
    cl.nHour = 25;
    cl.nMinute = 50;

    cl.pfn_set = SetTime;
    cl.pfn_set(&cl, 1, 2, 3);

    return 0;
}

