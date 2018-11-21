// 7.cpp : Defines the entry point for the console application.
//

/*
使用下面的宏扩展在使用的时候是否存在问题，请举例说明：
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
  printf("X求值得 %d\r\n", X(++n));

	return 0;
}
/*
#define X(n) ((n)+(n+1))
这样定义程序对以后的使用留下了隐患，
比如有个变量n=1本来想要的结果是 1 + 2 = 3;

宏的话只负责替换，但是有问题，看案例。

//X(++n);
//#define X(n) ((n)+(n+1))
//        X(++n) ((++n) + (n+1))
//          2      3       3  = 7
printf("X求值得 %d\r\n", X(++n));

*/
