// statistical tool.cpp : Defines the entry point for the console application.
//

/*
дһ������ͳ�ƹ��ߣ����г�����������ע������������������
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct stCode {
  int nTotalLine;
  int nCommentLine;
  int nEmptyLine;
}stc = {0};

//�������
void OutPutAnEmptyLine()
{
  cout << "\r\n";
}

//��ȡ��ʽ: ���ж�ȡ, ���ж����ַ���, ��֮���ûس���������
//If you want to avoid reading into character arrays, 
//you can use the C++ string getline() function to read lines into strings
void ReadDataFromFileLBLIntoString()
{
  string filename = "test_file.txt";
  ifstream fin( filename.c_str());
  if( !fin )
  {
    cout << "Error opening " << filename << " for input" << endl;
    exit(-1);
  }

  string s;
  while(getline(fin, s))
  {
    //ͳ��������
    stc.nTotalLine++;
    //ͳ��ע���� // /* */
    if(s.find("//") != s.npos || s.find("/*") != s.npos || s.find("*/") != s.npos)
    {
      stc.nCommentLine++;
    }
    //ͳ�ƿ���
    if(s.empty())
    {
      stc.nEmptyLine++;
    }
    cout << "Read from file: " << s << endl;
  }
}

void ShowResult()
{
  std::cout << "�ܼ��� " << stc.nTotalLine << " ��" << std::endl;
  std::cout << "ע���� " << stc.nCommentLine << " ��" << std::endl;
  std::cout << "������ " << stc.nEmptyLine << " ��" << std::endl;
  std::cout << std::endl;
}

int main(int argc, char* argv[])
{
  ReadDataFromFileLBLIntoString();
  OutPutAnEmptyLine();
  ShowResult();
  return 0;
}