// 3.cpp : Defines the entry point for the console application.
//

/*
写一个程序，在其中尝试以下操作： 
(1)创建一个引用，在其创建时没有被初始化。 
（2)在一个引用被初始化后，改变它的指向，使之指向另一个对象。 
（3)创建一个NULL引用。
*/

#include "stdafx.h"
#include <iostream>
#include <cstddef>

int main(int argc, char* argv[])
{
  
  /*
  (1)创建一个引用，在其创建时没有被初始化。 
  int n = 6;
  int &p;
  error C2530: 'p' : references must be initialized
  */
  
  /*
  （2)在一个引用被初始化后，改变它的指向，使之指向另一个对象。 
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
  （3)创建一个NULL引用。
  
  const int &p = NULL;
  //p is 0
  printf("p is %d\r\n", p);
  */

	printf("Hello World!\n");
	return 0;
}

