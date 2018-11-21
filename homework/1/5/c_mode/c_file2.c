#include <stdio.h>

extern const int nSize = 101;

void foo_test_const()
{
  printf("c_file2 const is %d\r\n", nSize);
}