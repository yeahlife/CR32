#include <stdio.h>
#include "c_const.h"

extern const int nSize = 100;

extern void foo_const_test();

int main()
{
  foo_const_test();

  printf("c_file2 const nSize is %d\r\n", nSize);
  return 0;
}

/*
error C2374: 'nSize' : redefinition; multiple initialization

see declaration of 'nSize'
*/