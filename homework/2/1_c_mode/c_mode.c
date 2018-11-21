// c_mode.c : Defines the entry point for the console application.
//

#include <stdio.h>

struct bird{
  int nBird;
};

struct rock{
  int rock;
};

void main(){
  bird* b;
  //error C2065: 'bird' : undeclared identifier
  //error C2065: 'b' : undeclared identifier
  //warning C4552: '*' : operator has no effect; expected operator with side-effect
  rock* r;
  //error C2065: 'rock' : undeclared identifier
  //error C2065: 'r' : undeclared identifier
  //warning C4552: '*' : operator has no effect; expected operator with side-effect
  void* v;
  //error C2143: syntax error : missing ';' before 'type'
  v = r;
  //error C2065: 'v' : undeclared identifier
  b = v;
  //error C2440: '=' : cannot convert from 'void *' to 'struct bird *'
}

