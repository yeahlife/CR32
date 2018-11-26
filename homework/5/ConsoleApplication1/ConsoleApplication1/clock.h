#pragma once

// 普通的函数指针
typedef int(*PFN_SetTime)(struct tagClock* this, int nH, int nM, int nS);

struct tagClock
{
    //数据
    int nHour;
    int nMinute;
    int nSecond;

    //行为，函数声明
    PFN_SetTime pfn_set;
};

int SetTime(struct tagClock* pClock, int nH, int nM, int nS);
