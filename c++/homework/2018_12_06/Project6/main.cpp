/*��Ϊ�������ƶ��ýӿڣ�ʹ�������Լ��ݷ��ϴ˱�׼�ӿڵ��������������Կ���(������ʵ�֣���Ӧ�Ľӿڼ�Ϊ����ͳһ��׼��Ϊͳһ����)��*/
#include <iostream>

class CMotherBoard
{
public:
    virtual void Sounding(int i) {}
    virtual void Networking(int i) {}
    virtual void Display(int i) {}
};


class CSoundCardA : public CMotherBoard
{
public:
    void Sounding(int i)
    {
        std::cout << "����A������" << std::endl;
    }
};
class CSoundCardB : public CMotherBoard
{
public:
    void Sounding(int i)
    {
        std::cout << "����B������" << std::endl;
    }
};
class CNetCardA : public CMotherBoard
{
public:
    void Networking(int i)
    {
        std::cout << "����A������" << std::endl;
    }
};
class CNetCardB : public CMotherBoard
{
public:
    void Networking(int i)
    {
        std::cout << "����B������" << std::endl;
    }
};

class CDisplayCardA : public CMotherBoard
{
public:
    void Display(int i)
    {
        std::cout << "�Կ�A������" << std::endl;
    }
};
class CDisplayCardB : public CMotherBoard
{
public:
    void Display(int i)
    {
        std::cout << "�Կ�B������" << std::endl;
    }
};
int main()
{
    CSoundCardA soundCard;
    CNetCardB netCard;
    CDisplayCardA displayCard;

    ((CMotherBoard*)&soundCard)->Sounding(1);
    ((CMotherBoard*)&netCard)->Networking(1);
    ((CMotherBoard*)&displayCard)->Display(1);

}
