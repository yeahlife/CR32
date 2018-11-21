// cpp_mode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <windows.h>

int main(int argc, char* argv[])
{
  time_t rawtime;
  
  time (&rawtime);
  const char *nTime = ctime (&rawtime);

	printf ("1 The current local time is: %s", nTime);

  Sleep(3000);

  nTime = ctime (&rawtime);
  
	printf ("2 The current local time is: %s", nTime);
	return 0;
}
/*
1 The current local time is: Tue Nov 20 20:54:30 2018
2 The current local time is: Tue Nov 20 20:54:30 2018

const 值一旦确定下来，不在改变
*/

