#include "stdafx.h"

#define int BOOL

int main()
{
  BOOL nRet = FALSE;

  //if(nRet == true)���Ե���Ҫ��ôд����low
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