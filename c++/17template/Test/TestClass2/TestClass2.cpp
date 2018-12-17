// TestClass2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

template<typename T>
class CTest {
public:
    CTest(T n) {
        m_nTest = n;
    }

    void foo(T n);

private:
    T m_nTest;

    //��̬���ݳ�Ա
    static T m_nStatic;
};

template<typename T>
T CTest<T>::m_nStatic;


//��ģ�庯��
template<typename T>
void CTest<T>::foo(T n) {
    m_nTest = n;
    m_nStatic = 1;
}

//��ģ�庯������
//template<>
//void CTest<char*>::foo(char* n) {
//    m_nTest = n;
//}

//��ģ������
//template<>
//class CTest<char*> {
//public:
//    CTest(char* n) {
//        m_nTest = n;
//    }
//
//    void foo(char* n) {
//        m_nTest = n;
//    }
//
//private:
//    char* m_nTest;
//};



int main()
{


    CTest<int> t(1);
    t.foo(123);
    //
    //char* p = "123";
    //CTest<char*> t2(p);
    //t2.foo(p);


    return 0;
}

