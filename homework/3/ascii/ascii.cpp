// ascii.cpp : Defines the entry point for the console application.
//

/*
��C++��Ascii���(�ֱ���ʮ���ƣ��ַ���ʮ������,�˽���)�������̨�ϡ�
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
  int i = 0;
  char ch_Hx[10] = {0};
  char ch_Oct[10] = {0};
  cout<<"ʮ����"<<"\t"<<"�ַ�"<<"\t"<<"ʮ������"<<"\t"<<"�˽���"<<endl;
  for(i=0;i<128;i++)
  {
    itoa(i,ch_Hx,16); 
    itoa(i,ch_Oct,8); 
    cout<<i<<"\t "<<(char)i<<"\t "<<ch_Hx<<"\t\t"<<ch_Oct<<endl;
  } 
  return 0;
}