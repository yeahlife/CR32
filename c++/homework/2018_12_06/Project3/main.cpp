/*����˵�����캯�������������е����麯���Ƿ�������ã�Ϊʲô��*/

#include <iostream>
class CClassA
{
public:
    virtual void func()
    {
        std::cout << "CClassA::func" << std::endl;
    }
    CClassA()
    {
        func();//ֱ�ӵ���
    }
    ~CClassA()
    {
        func();
    }
};

int main()
{
    CClassA ca;
    return 0;
}