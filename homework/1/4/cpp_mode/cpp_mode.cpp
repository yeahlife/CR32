#include <stdio.h>

const int nSize = 100;

int nSize2 = nSize;

//const int nSize2 = nSize;

int main()
{
  return 0;
}

/*
目的：想要将常量表达式nSize的值赋值给nSize2
问题：C语法提示error C2099: initializer is not a constant
结论：C语法赋值，期望这个变量值也是常量
      Cpp可以编译通过。
*/