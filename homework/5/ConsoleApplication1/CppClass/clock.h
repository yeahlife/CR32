#pragma once

class tagClock
{
private:
    //����
    int nHour;
    int nMinute;
    int nSecond;

public:
    //��Ϊ���������� 
    // ����ʱ��
    int __stdcall SetTime(int nH, int nM, int nS);
    // ��ȡʱ�� Hour
    int __stdcall GetHour();
    // ��ȡʱ�� Minute
    int __stdcall GetMinute();
};
