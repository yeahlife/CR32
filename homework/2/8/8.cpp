// 8.cpp : Defines the entry point for the console application.
//

/*
8.��������������ͬ�ĺ���f1()��f2()��
f1()������������f2()�Ƿ�����������
ʹ���еı�׼C�⺯��clock()��������������Ŀ�ʼ��ͽ����㣬
�Ƚ����ǿ���һ�����еø��죬Ϊ�˵õ���Ч�����֣�
Ҳ����Ҫ�ڼ�ʱѭ�����ظ�����������������
*/

#include "stdafx.h"
#include <time.h>
#include "8.h"

//#define CLOCKS_PER_SEC ((clock_t)1000)  //������ʾһ���ӻ��ж��ٸ�ʱ�Ӽ�ʱ��Ԫ

int f2(int a, int b)
{
  return a > b ? a : b;
}

int main(int argc, char* argv[])
{
	int nCount = 100;

  clock_t start = NULL;
  clock_t finish = NULL;
  clock_t start2 = NULL;
  clock_t finish2 = NULL;
  double dblTheTimes = NULL;
  double dblTheTimes2 = NULL;
  
  //inline f1()
  start = clock();
  while(nCount--)
  {
    f1(1, 2);
  }
  finish = clock();
  dblTheTimes=(double)((finish-start)/CLOCKS_PER_SEC);

  //f2()
  start2 = clock();
  while(nCount--)
  {
    f2(1, 2);
  }
  finish2 = clock();
  dblTheTimes2=(double)((finish2-start2)/CLOCKS_PER_SEC);

  printf("f1() %f�롣\r\n", dblTheTimes);
  printf("f2() %f�롣\r\n", dblTheTimes2);
  

	return 0;
}
/*
f1() 0.000000�롣
f2() 68.000000�롣
*/

