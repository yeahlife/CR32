/*
дһ��Ա����,�����з�нˮ�ķ�����
дһ����Ŀ�����࣬���̳���Ա���ࡣ
дһ������Ա�࣬Ҳ�̳���Ա���ࡣ
��ʵ�ֲ����ֳ����Ƿ�нˮ�Ķ�̬��
*/

#include "stdafx.h"

class CEmployee {
public:
    virtual void paySalary() = NULL;
};

void CEmployee::paySalary()
{
}

class CManager:public CEmployee {
public:
    virtual void paySalary() {
        printf("CManager::paySalary()\r\n");
    }
};

class CProgrammer:public CEmployee {
public:
    virtual void paySalary() {
        printf("CProgrammer::paySalary()\r\n");
    }
};

int main()
{
    CEmployee* pEmp = NULL;

    //Manager
    pEmp = new CManager();
    pEmp->paySalary();

    //Programmer
    pEmp = new CProgrammer();
    pEmp->paySalary();
    return 0;
}
