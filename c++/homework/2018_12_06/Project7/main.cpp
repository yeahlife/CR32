/*��ѧԱ¼������е�ѧ������ʦ�����̬�ԣ�
����Ӧ��ͬ��ѧ��(ѧ������˵����Ա���������е�ѧ���������������ǵ�˵��������Ϊ����)
����ʦ�Ķ�̬��(��ʦ��Ϊ�Ͻ�ʦ���½�ʦ���Ͻ�ʦ����������ѧ���½�ʦϲ���ö�ý���ѧ����ʦ�н�ѧ�����Ա����)*/

#include <iostream>
class CStudent
{
public:
    virtual void Express() = 0; //���
};
class CTeacher
{
public:
    virtual void Teach() = 0; 
};

class CNormalStu : public CStudent
{
public:
    void Express()
    {
        std::cout << "��ͨѧ��˵��" << std::endl;
    }
};
class CDisabledStu : public CStudent
{
public:
    void Express()
    {
        std::cout << "������:����" << std::endl;
    }
};

class COldTea : public CTeacher
{
public:
    void Teach()
    {
        std::cout << "������ѧ" << std::endl;
    }
};
class CNewTea : public CTeacher
{
public:
    void Teach()
    {
        std::cout << "��ý���ѧ" << std::endl;
    }
};

int main()
{
    CNormalStu normalStu;
    CDisabledStu disabledStu;
    COldTea oldTea;
    CNewTea newTea;
    ((CStudent*)(&normalStu))->Express();
    ((CStudent*)(&disabledStu))->Express();
    ((CTeacher*)(&oldTea))->Teach();
    ((CTeacher*)(&newTea))->Teach();


    return 0;
}