// TestFriend.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//��Ԫ friend


class CTest {
public:
    void foo();
};

class CTest2 {
public:
    void foo();

};

class CStudent {
    //��Ԫȫ�ֺ���
    friend void foo();

    //��Ԫ��Ա����
    friend void CTest::foo();

    //��Ԫ��
    friend class CTest2;

public:
    
    CStudent() {
    
    }

private:
    int m_nGender;
};

void foo() {
    CStudent stu;

    stu.m_nGender = 1;
}

void CTest::foo() {
    CStudent stu;
    stu.m_nGender = 1;
}

void CTest2::foo() {
    CStudent stu;
    stu.m_nGender = 1;
}

int main()
{
    CTest2 t;
    t.foo();

    return 0;
}

