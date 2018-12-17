// TestInherit.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//��ģ��̳�
template <typename T>
class CFather {
public:

private:
    T m_nTest;
};

template <typename T>
class CSon : public CFather<T>{
public:
    CSon() {
        m_nSon = 1;
    }
private:
    T m_nSon;
};

//��ģ��̳�����
template <>
class CSon<char*> : public CFather<char*> {
public:
    CSon() {
        m_nSon = "123";
    }
private:
    char* m_nSon;
};

int main()
{
    CSon<char*> son;

    return 0;
}

