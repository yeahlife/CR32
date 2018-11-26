#include "stdafx.h"

namespace CR32 {
  int m = 2;
}

int main()
{
  using CR32::m;

  printf("m is %d\r\n", m);
  
  return 0;
}
/*
output:
m is 2
*/