// cpp_mode.cpp : Defines the entry point for the console application.
//
/*
8.ʹ�ò�ͬ��������ʽ����
  ����ָ��const long��ָ�룬
  һ��ָ��ָ��һ��long���顣
  ��ʾ����ָ�����Ӻͼ��٣������ܸı�����ָ���ֵ��
*/
#include "stdafx.h"

int main(int argc, char* argv[])
{
  long nl[5] = {1,2,3,4,5};
  
  const long *pL1= nl;

  long *pl3 = nl;

  long const *pL2 = nl; 

  
/*  printf("pl3��2��ֵ��%d\r\n", (int)pl3[2]);*/
  printf("n1�ĵ�ַ��%p\r\n", &nl);

	printf("pL1��ֵ%p\r\n", *pL1);
  printf("pL1�ĵ�ַ%p\r\n", &pL1);
  printf("pL1�ĵ�ַ��1%p\r\n", &pL1-1);

  printf("pL2��ֵ%p\r\n", *pL2);
  printf("pL2�ĵ�ַ%p\r\n", &pL2);
  printf("pL2�ĵ�ַ��1%p\r\n", &pL2 + 1);

	return 0;
}

/*
n1�ĵ�ַ��0019FF2C

pL1��ֵ00000001
pL1�ĵ�ַ0019FF28
pL1�ĵ�ַ��10019FF24

pL2��ֵ00000001
pL2�ĵ�ַ0019FF20
pL2�ĵ�ַ��10019FF24
*/
