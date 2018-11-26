// 5.cpp : Defines the entry point for the console application.
//

/*
在文件Arithmetic.cpp中，说明在一个函数中使用的using指令并不能扩展到这个函数的范围之外。
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

  Integer x; //在这里想要调用命名空间Int中的结构体元素，提示未定义。
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

