#include <stdio.h>

const int nSize = 100;

int nSize2 = nSize;

//const int nSize2 = nSize;

int main()
{
  return 0;
}

/*
Ŀ�ģ���Ҫ���������ʽnSize��ֵ��ֵ��nSize2
���⣺C�﷨��ʾerror C2099: initializer is not a constant
���ۣ�C�﷨��ֵ�������������ֵҲ�ǳ���
      Cpp���Ա���ͨ����
*/