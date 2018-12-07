/*
写一个员工类,其中有发薪水的方法。
写一个项目经理类，他继承自员工类。
写一个程序员类，也继承自员工类。
请实现并表现出他们发薪水的多态性
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
