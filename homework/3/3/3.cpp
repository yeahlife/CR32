// 3.cpp : Defines the entry point for the console application.
//

/*
 2.创建一个包含一个名字空间的头文件。在名字空间里声明几个函数。
 再创建另一个头文件，它包含第一个头文件，并在先前的名字空间的基础上再增加几个函数声明。
 写一个包含第二个头文件的cpp文件。
 把名字空间用一个短的别名代替。
 在函数定义里使用作用域运算符调用这些函数。
 在另外一个单独的函数里，通过using指令把名字空间引入到函数中。
 并证实：这时并不需要作用域运算符调用名字空间里的函数。
*/
#include "stdafx.h"
#include "namespace2.h"

namespace c=CR32;

void CallFoo()
{
  using namespace c;
  foo2();
}

int main(int argc, char* argv[])
{
  c::foo1();
  CallFoo();

	return 0;
}
/*
output:
foo1()
foo2()
*/

