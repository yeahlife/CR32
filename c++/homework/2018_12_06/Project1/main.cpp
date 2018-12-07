/*��Ԥ�Ⲣ˵������ִ�н��,���Դ�Ϊ�����ܽḲ�ǡ����ء����ص����𣨴�������������ʵ��ԭ�������*/


#include <stdlib.h>
#include <iostream>
using namespace std;
class Base
{
public:
    virtual void Handle1(float x)
    {
        cout << "Base::Handle1(float) " << x << endl;
    }
    void Handle2(float x)
    {
        cout << "Base::Handle2(float) " << x << endl;
    }
    void Handle3(float x)
    {
        cout << "Base::Handle3(float) " << x << endl;
    }
};

class Derived : public Base
{
public:
    virtual void Handle1(float x)
    {
        cout << "Derived::Handle1(float) " << x << endl;
    }
    void Handle2(int x)
    {
        cout << "Derived::Handle2(int) " << x << endl;
    }
    void Handle3(float x)
    {
        cout << "Derived::Handle3(float) " << x << endl;
    }
    void Handle3(double x)
    {
        cout << "Derived::Handle3(double) " << x << endl;
    }
};
/* �۲�������������ʵ�֣���Ԥ������main�е�ִ�н����
ע�����㣺
1. ���õķ������ĸ�
2. ������ɵ�ԭ�������ء����ǡ������е���һ�֣�
*/
void main(void)
{
    Derived DervObj;
    Base *pBase = &DervObj;
    Derived *pDerv = &DervObj;

    pBase->Handle1(3.14f);
    //���� Base*
    //Base�� �����ƥ�亯��
    //virtual void Handle1(float x);
    //ָ�룬��ӵ���
    //�������DervObj��������õ���Derived��virtual void Handle1(float x)


    pDerv->Handle1(3.14f);
    //pDerv���ͣ�Derived
    //Derived�����ƥ��ĺ�����virtual void Handle1(float x)
    //�麯����ָ�룬��ӵ���
    //�������Derived��������õ���Derived��virtual void Handle1(float x)

    cout << endl;

    pBase->Handle2(3.14f);
    //pBase���ͣ�Base*
    //Base���������ƥ��ĺ�����
    //�����麯����ֱ�ӵ���Base����void Handle2(float x)


    pDerv->Handle2(3.14f);
    //pDerv���ͣ�Derived *  
    //��Derived �����ƥ�䣺void Handle2(int x)
    //�����麯����ֱ�ӵ���Derived����void Handle2(float x)

    cout << endl;

    pBase->Handle3(3.14f);
    //pBase���ͣ�Base *
    //Base�������ƥ�亯�� void Handle3(float x)
    //�����麯����Base����void Handle3(float x)
    //

    pDerv->Handle3(3.14f);
    //pDerv���ͣ�Derived*
    //Derived�������ƥ�亯�� void Handle3(float x)
    //�����麯����Derived����void Handle3(float x)

    pDerv->Handle3(3.14);
    //pDerv���ͣ�Derived *
    //Derived�������ƥ�亯�� void Handle3(double x)
    //�����麯����Derived����void Handle3(double x)

    cout << endl;

    pDerv->Handle3(3);
    //pDerv���ͣ�Derived*
    //Derived����ƥ�亯��  void Handle3(float x)
    //                   void Handle3(double x)
    //                   �����ԣ�
}