// 4.cpp : Defines the entry point for the console application.
//

/*
дһ���������ú���ʹ��ָ����Ϊ�������޸�ָ����ָ���ݣ�Ȼ�������÷���ָ����ָ�����ݡ�
*/

#include "stdafx.h"

int& foo_ref(int* p)
{
  *p = 5;
  return (*p);
}
int main(int argc, char* argv[])
{
	int n = 6;

  printf("&n is %d\r\n", foo_ref(&n));
  //&n is 5
	return 0;
}

