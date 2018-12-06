/*
3.
在题目2的基础上进一步，
创建一个通过传值方式接收Shape对象参数的函数，
并试着向上类型转换一个派生类对象作为参数。
看看结果如何。
通过把参数设为Shape对象的引用来修改这个函数。

*/
#include "stdafx.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

int main()
{
    CShape shape;
    CShape &rshape = shape;
    shape.passRefDisplay(rshape);//Shape

    CCircle circlr;
    CCircle &rcirclr = circlr;
    circlr.passRefDisplay(rcirclr);//Circle

    CSquare square;
    CSquare &rsquare = square;
    square.passRefDisplay(rsquare);//Square

    CTriangle triangle;
    CTriangle &rtriangle = triangle;
    triangle.passRefDisplay(rtriangle);//Triangle

    return 0;
}

/*
output:
CShape::draw()
CCircle::draw()
CSquare::draw()
CTriangle::draw()
*/


