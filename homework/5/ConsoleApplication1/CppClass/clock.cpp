#include "stdafx.h"
#include "clock.h"

//�����Ķ��壬��Ҫ���Ͻṹ����������
int tagClock::SetTime(int nH, int nM, int nS)
{
    //thisָ���ʾ��ǰ���øú����Ķ���ĵ�ַ
    this->nHour = nH;
    this->nMinute = nM;
    this->nSecond = nS;

    return 0;
}

// ��ȡʱ�� Hour
int tagClock::GetHour()
{
    return (this->nHour);
}

// ��ȡʱ�� Minute
int tagClock::GetMinute()
{
    return (this->nMinute);
}
