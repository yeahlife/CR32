// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct bird{
    int nBird;
};

struct rock{
  int rock;
  //error C2380: type(s) preceding 'rock' (constructor with return type, or illegal redefinition of current class-name?)
};

void main(){
  bird* b;
  rock* r;
  void* v;
  v = r;
  b = v;
  //error C2440: '=' : cannot convert from 'void *' to 'struct bird *'
}

