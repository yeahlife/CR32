// 7.cpp : Defines the entry point for the console application.
//

/*
ʹ������ĺ���չ��ʹ�õ�ʱ���Ƿ�������⣬�����˵����
#define X(n) ((n)+(n+1))
*/

#include "stdafx.h"
#define X(n) ((n)+(n+1))

int main(int argc, char* argv[])
{
  int n = 1;
  //X(++n);
  //#define X(n) ((n)+(n+1))
  //        X(++n) ((++n) + (n+1))
  //          2      3       3  = 7
  printf("X��ֵ�� %d\r\n", X(++n));

	return 0;
}
/*
#define X(n) ((n)+(n+1))
�������������Ժ��ʹ��������������
�����и�����n=1������Ҫ�Ľ���� 1 + 2 = 3;

��Ļ�ֻ�����滻�����������⣬��������

//X(++n);
//#define X(n) ((n)+(n+1))
//        X(++n) ((++n) + (n+1))
//          2      3       3  = 7
printf("X��ֵ�� %d\r\n", X(++n));

*/
