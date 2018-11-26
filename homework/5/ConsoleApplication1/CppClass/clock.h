#pragma once

class tagClock
{
private:
    //数据
    int nHour;
    int nMinute;
    int nSecond;

public:
    //行为，函数声明 
    // 设置时间
    int __stdcall SetTime(int nH, int nM, int nS);
    // 获取时间 Hour
    int __stdcall GetHour();
    // 获取时间 Minute
    int __stdcall GetMinute();
};
