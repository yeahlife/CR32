// 3.cpp : Defines the entry point for the console application.
//

/*
 2.����һ������һ�����ֿռ��ͷ�ļ��������ֿռ�����������������
 �ٴ�����һ��ͷ�ļ�����������һ��ͷ�ļ���������ǰ�����ֿռ�Ļ����������Ӽ�������������
 дһ�������ڶ���ͷ�ļ���cpp�ļ���
 �����ֿռ���һ���̵ı������档
 �ں���������ʹ�������������������Щ������
 ������һ�������ĺ����ͨ��usingָ������ֿռ����뵽�����С�
 ��֤ʵ����ʱ������Ҫ������������������ֿռ���ĺ�����
*/
#include "stdafx.h"
#include "namespace2.h"

namespace c=CR32;

void CallFoo()
{
  using namespace c;
  foo2();
}

int main(int argc, char* argv[])
{
  c::foo1();
  CallFoo();

	return 0;
}
/*
output:
foo1()
foo2()
*/

