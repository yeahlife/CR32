/*���������Ŀ1�У�ʹ��draw()�Ǵ��麯�������Դ���һ������ΪShape�Ķ���
�������ڹ��캯���ڵ���������麯�������������Ρ��������Ĵ����ԣ���draw()���ж��塣*/

#include <iostream>

//class CShape
//{
//public:
//    virtual void draw() = 0;
//    CShape()
//    {
//        draw();
//    }
//};

class IShape
{
public:
    virtual void draw() = 0;
};
class CCircle : public IShape
{
public:
    void draw()
    {
        std::cout << "draw CCircle" << std::endl;
    }
};
class CSquare : public IShape
{
public:
    void draw()
    {
        std::cout << "draw CSquare" << std::endl;
    }
};
class CTriangle : public IShape
{
public:
    void draw()
    {
        std::cout << "draw CTriangle" << std::endl;
    }
};

int main()
{
    //CShape shape;//������ʵ����

}