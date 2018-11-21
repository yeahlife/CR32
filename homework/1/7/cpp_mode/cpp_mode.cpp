// cpp_mode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

extern const int nSize = 101;

extern void foo_const_test();

int main(int argc, char* argv[])
{
	printf("main const int is %d\r\n", nSize);

  foo_const_test();

	return 0;
}

/*
output:

main const int is 101
cpp_file2 const int nSize is 101
*/

