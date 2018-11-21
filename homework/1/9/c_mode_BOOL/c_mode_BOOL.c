#include <stdio.h>

typedef enum { BFALSE, BTRUE } bool_t;

int main()
{
  bool_t nRet = BTRUE;
 
  if(nRet)
  {
    printf("bool true %d\r\n", nRet); //1
    printf("bool true %s\r\n", nRet); //
  }
  else
  {
    printf("bool false %d\r\n", nRet); //0
    printf("bool false %s\r\n", nRet); //(null)
  }
  
  return 0;
}