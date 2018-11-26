#pragma once
class tagClock {
private:
    //数据
    int nHour;
    int nMinute;
    int nSecond;

public:
    //行为，函数声明
    int __stdcall SetTime(int nH, int nM, int nS);
};