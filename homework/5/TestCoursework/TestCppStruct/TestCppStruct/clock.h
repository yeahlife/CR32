#pragma once
class tagClock {
private:
    //����
    int nHour;
    int nMinute;
    int nSecond;

public:
    //��Ϊ����������
    int __stdcall SetTime(int nH, int nM, int nS);
};