#include "stdafx.h"

#include "clock.h"

// 类中的函数指针
// 调用方式 2 | 3 
typedef int(__stdcall tagClock::*PFN_SetTimeClass)(int nH, int nM, int nS);
typedef int(__stdcall tagClock::*PFN_GetHourClass)();
typedef int(__stdcall tagClock::*PFN_GetMinuteClass)();

int main()
{
    // 调用方式 1
    //tagClock cl1;
    //cl1.SetTime(1, 2, 3);
    //cl1.GetHour();
    //cl1.GetMinute();


    // 调用方式 2
    //tagClock cl1;
    //PFN_SetTimeClass pfn_class;
    //pfn_class = &tagClock::SetTime;
    //(cl1.*pfn_class)(1, 2, 3);

    //PFN_GetHourClass pfn_class_gethour;
    //pfn_class_gethour = &tagClock::GetHour;
    //int nHour = 0;
    //nHour = (cl1.*pfn_class_gethour)();

    //PFN_GetMinuteClass pfn_class_getminute;
    //pfn_class_getminute = &tagClock::GetMinute;
    //int nMinute = 0;
    //nMinute = (cl1.*pfn_class_getminute)();


    // 调用方式 3
    //tagClock cl1;
    //tagClock* pCL = &cl1;
    //PFN_SetTimeClass pfn_class;
    //pfn_class = &tagClock::SetTime;
    //(pCL->*pfn_class)(1, 2, 3);

    //PFN_GetHourClass pfn_class_gethour;
    //pfn_class_gethour = &tagClock::GetHour;
    //int nHour = 0;
    //nHour = (pCL->*pfn_class_gethour)();

    //PFN_GetMinuteClass pfn_class_getminute;
    //pfn_class_getminute = &tagClock::GetMinute;
    //int nMinute = 0;
    //nMinute = (pCL->*pfn_class_getminute)();

    return 0;
}