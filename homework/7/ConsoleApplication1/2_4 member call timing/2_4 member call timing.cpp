// 2_4 member call timing.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MemberObj.h"

int main()
{
    CMemberObj memobj1;

    CMemberObj memobj2(2);

    return 0;
}
/*
output:
CMemberObj()
CMemberObj(int n)2
~CMemberObj()
~CMemberObj()
*/

/*
������Ա��
1. ֻ�е������Ա���ڵ������޲ι��캯��ʱ��
�������Ż�����ʽ��ʼ���б��ķ�ʽ�Զ����Ա���г�ʼ����
��һ����û���κι��캯��ʱ��C++�����һ��Ĭ���޲ι��캯��;
һ���������κι��캯����C++�Ͳ�������޲ι��캯���ˣ�
������ʾ�����޲ι��캯�������ṩȱʡ�����Ĺ��캯����

2. ������ж����Աʱ��Ӧ�ò��ó�ʼ���б��ķ�ʽ�������г�ʼ����

3. �����Ա�Ĺ�����������������е�����������ͬ���������ڹ��캯����ʼ���б��еĴ����޹ء�
*/
