#include <stdio.h>
#include "c_const.h"

extern foo_const_test();

int main()
{

  foo_const_test();
    //const int nSize = 100;
  printf("c_file1 const nSize is %d\r\n", nSize);
  return 0;
}

/*
error C2374: 'nSize' : redefinition; multiple initialization

see declaration of 'nSize'
*/