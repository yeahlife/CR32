#pragma once
#include <string>
#include "MyException.h"

class CMyFileException : public CMyException
{
public:
    enum FILE_EXCPT_TYPE{
        FILE_EXCPT_OPEN, //��ʧ��
        FILE_EXCPT_READ, //���ļ�ʧ��
        FILE_EXCPT_WRITE, //д�ļ�ʧ��
    };


    CMyFileException(FILE_EXCPT_TYPE type, std::string str = "�ļ�����");
    ~CMyFileException();


    FILE_EXCPT_TYPE m_Type;

};

