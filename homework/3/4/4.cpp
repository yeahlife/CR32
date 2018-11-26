// 4.cpp : Defines the entry point for the console application.
//

/*
请使用多种方式来引用std命名空间中的cout对象
（using namespace std/using std::)。
*/

/*
VC++6
namespace方法1
#include <iostream>

using namespace std;
*/
/*
#include "stdafx.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Hello World!\n" << endl;
	return 0;
}
*/

/*
VC++6
namespace方法2
#include <iostream.h>
*/
#include "stdafx.h"
#include <iostream.h>

int main(int argc, char* argv[])
{
  cout << "Hello World!\n" << endl;
  return 0;
}

/*
output:
Hello World!
*/


