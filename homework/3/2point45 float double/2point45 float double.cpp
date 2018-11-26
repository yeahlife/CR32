// 2point45 float double.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
  float fn = 2.45f;
	
  cout << (int)fn << endl;
  cout << fn << endl;
  cout << setprecision(32) << fn << endl;
  
	return 0;
}
/*
2
2.45
2.45000004768372
*/
