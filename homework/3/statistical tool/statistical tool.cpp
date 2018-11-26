// statistical tool.cpp : Defines the entry point for the console application.
//

/*
写一个代码统计工具，：列出代码行数，注释行数，空行行数等
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

//输出空行
void OutPutAnEmptyLine()
{
  cout << "\r\n";
}

//读取方式: 逐行读取, 将行读入字符串, 行之间用回车换行区分
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
    //统计总行数
    stc.nTotalLine++;
    //统计注释行 // /* */
    if(s.find("//") != s.npos || s.find("/*") != s.npos || s.find("*/") != s.npos)
    {
      stc.nCommentLine++;
    }
    //统计空行
    if(s.empty())
    {
      stc.nEmptyLine++;
    }
    cout << "Read from file: " << s << endl;
  }
}

void ShowResult()
{
  std::cout << "总计有 " << stc.nTotalLine << " 行" << std::endl;
  std::cout << "注释有 " << stc.nCommentLine << " 行" << std::endl;
  std::cout << "空行有 " << stc.nEmptyLine << " 行" << std::endl;
  std::cout << std::endl;
}

int main(int argc, char* argv[])
{
  ReadDataFromFileLBLIntoString();
  OutPutAnEmptyLine();
  ShowResult();
  return 0;
}