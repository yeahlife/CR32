/*
0. ���������Ŀ1�У�ʹ��draw()�Ǵ��麯����
���Դ���һ������ΪShape�Ķ���
�������ڹ��캯���ڵ���������麯�������������Ρ�
�������Ĵ����ԣ���draw()���ж��塣
*/

#include "stdafx.h"

class CShape {
public:
    CShape() {
        //draw(); //? ���캯���ڵ��ã����ޱ���
    }
    virtual void draw() = NULL;
    //virtual void draw(){}
};

class CCircle :public CShape {
public:
    virtual void draw() {
        printf("CCircle::draw()\r\n");
    }
};

int main()
{
    //CShape shape;//����ʵ�������麯��
    //shape.draw(); 

    //CShape *shape = new CShape();//����ʵ�������麯��
    //shape->draw();

    CShape *shape = new CCircle();
    shape->draw(); //draw()ʵ���˴��麯����shape�Ǹ���ָ����ã���ӵ��ã��������ǣ�

    return 0;
}

void CShape::draw()
{
}
