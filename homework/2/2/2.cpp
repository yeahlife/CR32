// 2.cpp : Defines the entry point for the console application.
//

/*
2. ������Ĵ�����뵽main�У������ʱ����һЩ˵������֤�����þ��൱�ڱ��Զ�������õ�ָ�롣
#include <iostream>
using namespace std;

  // Ordinary free-standing reference:
  int y;
  int& r = y;
  // When a reference is created, it must
  // be initialized to a live object.
  // However, you can also say:
  const int& q = 12; // (1)
  // References are tied to someone else's storage:
  int x = 0; // (2)
  int& a = x; // (3)
  int main() {
  cout << "x = " << x << ", a = " << a << endl;
  a++;
  cout << "x = " << x << ", a = " << a << endl;
} ///:~
*/

#include "stdafx.h"

int main(int argc, char* argv[])
{
	
  int y;
  int& r = y;
  int n = 12;

  printf("y �ڴ��ַ�� %p\r\n", &y);
  printf("r ָ����y���ڴ��ַ��r�д洢��ֵ��y�ĵ�ַ%p\r\n", &r);
  /*
  output:
  y �ڴ��ַ�� 0019FF3C
  r ָ����y���ڴ��ַ��r�д洢��ֵ��y�ĵ�ַ0019FF3C
  */

  const int &q  = n;//����12�ĵ�ַ�ǳ���ָ�룬����ҲӦ���ó���ָ��������
//  const int *p = &q;
  //int n = 12;
  //const int *q = &n;
  //12 �����һ���ڴ��ַ���洢��������0019ff30
  //��const int& q Ҳ�����һ���ڴ��ַ��qָ����12���ڴ��ַ������q�е�ֵ����0019ff30
//   printf("n���ڴ��ַ %p\r\n", &n);
//   printf("n���ڴ��ַ %p\r\n", &q);

//   printf("n��ֵ %p\r\n", q);
//   printf("n��ֵ %p\r\n", n);
//   printf("n��ֵ %p\r\n", *(&q));

  int x = 0; // (2)
  int& a = x; // (3)
  printf("n���ڴ��ַ %p\r\n", &x);
  printf("n���ڴ��ַ %p\r\n", &a);

	return 0;
}

