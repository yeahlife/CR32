// 6.cpp : Defines the entry point for the console application.
//

/*
����һ��������ʹ����char&���������޸ĸò�����
��main()�������ӡһ��char������ʹ���������������������������Ƶĺ�����
Ȼ���ٴδ�ӡ�˱�����֤�����ѱ��ı䡣������Ӱ���˳���Ŀɶ�����
*/


#include "stdafx.h"

void cchange(char& ch)
{
  ch = 'b';
  
  return;
}


int main(int argc, char* argv[])
{
  char cTest = 'a';
  
  printf("c %c\r\n", cTest);
  cchange(cTest);
  printf("c %c\r\n", cTest);
	printf("Hello World!\n");
	return 0;
}

/*
output:
c a
c b
*/

