// cout menu.cpp : Defines the entry point for the console application.
//

/*
把

  Menu
  ===================================
  1. Input the students’ names and scores
  2. Search scores of some students
  3. Modify scores of some students
  4. List all students’ scores
  5. Quit the system
  ===================================
  Please input your choise (1-5):
  -------------------------------------------------------------------------
用C++的cout输出
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

void menu()
{
  std::cout << "Menu" << std::endl;
  std::cout << "===================================" << std::endl;
  std::cout << "1. Input the students’ names and scores" << std::endl;
  std::cout << "2. Search scores of some students" << std::endl;
  std::cout << "3. Modify scores of some students" << std::endl;
  std::cout << "4. List all students’ scores" << std::endl;
  std::cout << "5. Quit the system" << std::endl;
  std::cout << "===================================" << std::endl;
  std::cout << "Please input your choise (1-5):" << std::endl;
}

int main(int argc, char* argv[])
{
	
  menu();

	return 0;
}

