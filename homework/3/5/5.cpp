// 5.cpp : Defines the entry point for the console application.
//

/*
���ļ�Arithmetic.cpp�У�˵����һ��������ʹ�õ�usingָ�������չ����������ķ�Χ֮�⡣
*/

#include "stdafx.h"

#include "NamespaceInt.h"
void arithmetic() {
  using namespace Int;
  Integer x;
  x.setSign(positive);
}

int main(){
  arithmetic();

  Integer x; //��������Ҫ���������ռ�Int�еĽṹ��Ԫ�أ���ʾδ���塣
  x.getSign();

  return 0;
} 
/*
Warning:
error C2065: 'Integer' : undeclared identifier
error C2146: syntax error : missing ';' before identifier 'x'
error C2065: 'x' : undeclared identifier
error C2228: left of '.getSign' must have class/struct/union type
*/

