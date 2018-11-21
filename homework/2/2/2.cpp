// 2.cpp : Defines the entry point for the console application.
//

/*
2. 将下面的代码放入到main中，在输出时增加一些说明，以证明引用就相当于被自动间接引用的指针。
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

  printf("y 内存地址是 %p\r\n", &y);
  printf("r 指向了y的内存地址，r中存储的值是y的地址%p\r\n", &r);
  /*
  output:
  y 内存地址是 0019FF3C
  r 指向了y的内存地址，r中存储的值是y的地址0019FF3C
  */

  const int &q  = n;//变量12的地址是常量指针，所以也应该用常量指针来引用
//  const int *p = &q;
  //int n = 12;
  //const int *q = &n;
  //12 会分配一个内存地址来存储，假如是0019ff30
  //那const int& q 也会分配一个内存地址，q指向了12的内存地址，所以q中的值就是0019ff30
//   printf("n的内存地址 %p\r\n", &n);
//   printf("n的内存地址 %p\r\n", &q);

//   printf("n的值 %p\r\n", q);
//   printf("n的值 %p\r\n", n);
//   printf("n的值 %p\r\n", *(&q));

  int x = 0; // (2)
  int& a = x; // (3)
  printf("n的内存地址 %p\r\n", &x);
  printf("n的内存地址 %p\r\n", &a);

	return 0;
}

