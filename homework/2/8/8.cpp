// 8.cpp : Defines the entry point for the console application.
//

/*
8.创建两个功能相同的函数f1()和f2()，
f1()是内联函数，f2()是非内联函数。
使用中的标准C库函数clock()标记这两个函数的开始点和结束点，
比较它们看哪一个运行得更快，为了得到有效的数字，
也许需要在计时循环中重复调用这两个函数。
*/

#include "stdafx.h"
#include <time.h>
#include "8.h"

//#define CLOCKS_PER_SEC ((clock_t)1000)  //用来表示一秒钟会有多少个时钟计时单元

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

  printf("f1() %f秒。\r\n", dblTheTimes);
  printf("f2() %f秒。\r\n", dblTheTimes2);
  

	return 0;
}
/*
f1() 0.000000秒。
f2() 68.000000秒。
*/

