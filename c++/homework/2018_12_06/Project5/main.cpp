/*дһ��Ա����,�����з�нˮ�ķ�����
дһ����Ŀ�����࣬���̳���Ա���ࡣдһ������Ա�࣬Ҳ�̳���Ա���ࡣ
��ʵ�ֲ����ֳ����Ƿ�нˮ�Ķ�̬��*/
#include <iostream>

class CEmployee
{
public:
    virtual void Payoff() = 0;
};

class CManager : public CEmployee
{
public:
    void Payoff()
    {
        std::cout << "������Ǯ" << std::endl;
    }
};

class CProgrammer : public CEmployee
{
public:
    void Payoff()
    {
        std::cout << "������Ա��Ǯ" << std::endl;
    }
};

int main()
{
    CManager mam;
    CProgrammer prg;
    ((CEmployee*)&mam)->Payoff();
    ((CEmployee*)&prg)->Payoff();
    return 0;
}