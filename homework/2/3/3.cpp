// 3.cpp : Defines the entry point for the console application.
//

/*
дһ�����������г������²����� 
(1)����һ�����ã����䴴��ʱû�б���ʼ���� 
��2)��һ�����ñ���ʼ���󣬸ı�����ָ��ʹָ֮����һ������ 
��3)����һ��NULL���á�
*/

#include "stdafx.h"
#include <iostream>
#include <cstddef>

int main(int argc, char* argv[])
{
  
  /*
  (1)����һ�����ã����䴴��ʱû�б���ʼ���� 
  int n = 6;
  int &p;
  error C2530: 'p' : references must be initialized
  */
  
  /*
  ��2)��һ�����ñ���ʼ���󣬸ı�����ָ��ʹָ֮����һ������ 
  */
  int n = 6;
  int m = 7;
  /*
  int &p = n;
  p = m;
  printf("p is %d\r\n", p);
  */
  /*
  const int &p = n;
  p = m;
  printf("p is %d\r\n", p);
  //error C2166: l-value specifies const object
  */

  /*
  ��3)����һ��NULL���á�
  
  const int &p = NULL;
  //p is 0
  printf("p is %d\r\n", p);
  */

	printf("Hello World!\n");
	return 0;
}

