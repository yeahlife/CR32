// 10.cpp : Defines the entry point for the console application.
//

/*
10.����һ��const�ַ������һ��ָ������鿪ʼ���ָ�룬
ʹ�����ָ���޸������е�Ԫ�أ������������Ƿ�ᱨ��Ӧ��������
���û�У�Ϊʲô����Ϊ����
*/

#include "stdafx.h"

int main(int argc, char* argv[])
{
  const char szBuf[10] = "hello";
  const char *p = szBuf;

	p[2] = 'r'; // error C2166: l-value specifies const object

	return 0;
}
/*
  const �Ǳ������﷨�����õĲ����޸�const���ͱ�����ֵ��
*/
