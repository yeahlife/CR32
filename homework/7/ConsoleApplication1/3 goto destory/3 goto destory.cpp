// 3 goto destory.cpp : 定义控制台应用程序的入口点。
//

/*
3.写程序演示，当用goto跳出一个循环时，析构函数仍被调用。
https://stackoverflow.com/questions/3179936/goto-out-of-a-block-do-destructors-get-called

The C++ Standard says:

On exit from a scope (however accomplished), 
destructors (12.4) are called for all constructed objects 
with automatic storage duration (3.7.2) (named objects or temporaries) 
that are declared in that scope, in the reverse order of their declaration.

So the answer is "yes".
*/
#include "stdafx.h"
#include "Goto.h"

int main()
{
    CGoto testgoto;

    testgoto.foo();
    return 0;
}

/*
output:
CGoto()
0
1
2
3
4
5
6
7
CGoto::foo()
~CGoto()
*/
