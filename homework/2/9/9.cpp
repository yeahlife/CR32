// 9.cpp : Defines the entry point for the console application.
//
/*
 9.����˵����ʱʹ�ú���Ĭ�ϲμ�ʹ��ʱ��Ҫע���ʲô��
*/

#include "stdafx.h"

void Func(int i = 1, float f = 2.0f, double d = 3.0)
{
  printf("%d %.1f %.1f\r\n", i, f, d);
}

int main(int argc, char* argv[])
{
	Func();// 1 2.0 3.0
  Func(2);// 2 2.0 3.0
  Func(2, 5.0f);//2 5.0 3.0
  Func(2, 5.0f, 6.0f);//2 5.0 6.0

	return 0;
}
/*
���ĳ��������Ĭ�ϲ�������ô������Ĳ������붼��Ĭ�ϲ���
Ĭ�ϲ������Է��ں����������߶����У���ֻ�ܷ��ڶ���֮һ
��������ʱ����ʹ��Ĭ�ϲ���ֵ
*/

