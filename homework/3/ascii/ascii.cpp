// ascii.cpp : Defines the entry point for the console application.
//

/*
用C++将Ascii码表(分别以十进制，字符，十六进制,八进制)输出控制台上。
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
  int i = 0;
  char ch_Hx[10] = {0};
  char ch_Oct[10] = {0};
  cout<<"十进制"<<"\t"<<"字符"<<"\t"<<"十六进制"<<"\t"<<"八进制"<<endl;
  for(i=0;i<128;i++)
  {
    itoa(i,ch_Hx,16); 
    itoa(i,ch_Oct,8); 
    cout<<i<<"\t "<<(char)i<<"\t "<<ch_Hx<<"\t\t"<<ch_Oct<<endl;
  } 
  return 0;
}