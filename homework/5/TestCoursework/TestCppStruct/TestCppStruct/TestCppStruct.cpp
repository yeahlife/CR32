#include "stdafx.h"
#include "clock.h"

//�������еĺ���ָ��
typedef int(__stdcall tagClock::*PFN_SetTimeClass)(int nH, int nM, int nS);
//�������ݣ��Ĵ��� ջ
// thiscall --> ������ĳ�Ա�����ĵ���Լ���� �������ڲ�ʹ��
// fastcall
// cdecl
// stdcall

int main()
{
    tagClock cl;

    //��1�ֵ��ó�Ա��������ʽ
    cl.SetTime(1, 2, 3);

    //��2�ֵ��ó�Ա��������ʽ��ͨ������ָ��
    PFN_SetTimeClass pfn_class;
    pfn_class = &tagClock::SetTime;
    (cl.*pfn_class)(11, 21, 31);

    //��3�ֵ��ó�Ա��������ʽ��ͨ��������������
    tagClock* pCL = &cl;
    //PNF_SetTimeClass pfn_class;
    //pfn_class = &tagClock::SetTime;
    (pCL->*pfn_class)(10, 20, 30);

    return 0;
}