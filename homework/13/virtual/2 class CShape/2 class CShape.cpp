/*
0. 在昨天的题目1中，使得draw()是纯虚函数。
尝试创建一个类型为Shape的对象。
并试着在构造函数内调用这个纯虚函数，看看结果如何。
保留它的纯虚性，对draw()进行定义。
*/

#include "stdafx.h"

class CShape {
public:
    CShape() {
        //draw(); //? 构造函数内调用，并无报错
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
    //CShape shape;//不能实例化纯虚函数
    //shape.draw(); 

    //CShape *shape = new CShape();//不能实例化纯虚函数
    //shape->draw();

    CShape *shape = new CCircle();
    shape->draw(); //draw()实现了纯虚函数，shape是父类指针调用，间接调用，函数覆盖，

    return 0;
}

void CShape::draw()
{
}
