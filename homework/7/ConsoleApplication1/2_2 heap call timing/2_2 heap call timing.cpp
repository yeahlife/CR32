// 2_2 heap call timing.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
2.����˵�����캯�������������ĵ���ʱ����ջ����ȫ�ֶ��󣬶Ѷ���,������Ա����
*/

#include "stdafx.h"
#include "HeapObj.h"
#include <iostream>

int main()
{
    // ������ڴ�
    CHeapObj *ptr = new CHeapObj();
    ptr->ShowMsg();

    // ��Ҫ�ֶ�����delete ptr ���ͷ��ڴ�
    delete ptr;

    return 0;
}

/*
�Ѷ��󣬶�̬���������

ʹ��new����������󴴽��ڶ��ڴ��С�

���ԣ�
13�д�ϵ�F9��
�۲�ptr�������ڶ��п�����һ���ڴ�ռ䣬
���ҵ�����CHeapObj�еĹ��캯��������Աֵ��ʼ��
ptr����ָ������CHeampObj�������͵�ָ�������

Ȼ��ptr->ShowMsg();��ӡһ����Ϣ��hello heap object

����ִ�г��򣬵�����ִ����ϣ�
����û�е�����������
���ڴ�û���ͷţ�
��Ҫ�����ֶ�����delete��������ͷ�������ڴ档
delete ptr;
*/

/*
CHeapObj()
hello heap object
*/

/*
delete ptr

�������ֶ�ִ�ж��ڴ��ͷŵ�ʱ�򣬻������������
CHeapObj()
hello heap object
~CHeapObj()
*/