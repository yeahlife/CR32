// 9 member func point.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
9.ʹ�ó�Ա����ָ�����������еĳ�Ա������
*/
#include "stdafx.h"
#include "test.h"

// ����һ�����еĺ���ָ��
typedef void(tagTest::*PFN_ShowMsgA)();
typedef void(tagTest::*PFN_ShowMsgB)();

int main()
{
    // ����tagTest����
    tagTest t;
    // ������ָ��ָ���Ӧ�ĺ���
    PFN_ShowMsgA pfn_showmsga;
    pfn_showmsga = &tagTest::ShowMsgA;
    // ͨ����Ա����ָ�������Ӧ����
    (t.*pfn_showmsga)();

    // ͬ�����ShowMsgB()
    PFN_ShowMsgB pfn_showmsgb;
    pfn_showmsgb = &tagTest::ShowMsgB;
    (t.*pfn_showmsgb)();

    return 0;
}

