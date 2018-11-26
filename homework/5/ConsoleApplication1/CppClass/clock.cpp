#include "stdafx.h"
#include "clock.h"

//函数的定义，需要加上结构体名作用域
int tagClock::SetTime(int nH, int nM, int nS)
{
    //this指针表示当前调用该函数的对象的地址
    this->nHour = nH;
    this->nMinute = nM;
    this->nSecond = nS;

    return 0;
}

// 获取时间 Hour
int tagClock::GetHour()
{
    return (this->nHour);
}

// 获取时间 Minute
int tagClock::GetMinute()
{
    return (this->nMinute);
}
