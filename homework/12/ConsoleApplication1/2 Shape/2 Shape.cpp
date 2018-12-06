// 2 Shape.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

int main()
{
    CShape* pShape = new CShape();
    pShape->draw();//Arms

    CCircle* pCircle = new CCircle();
    pShape = pCircle;
    pShape->draw();//Circle

    CSquare* pSquare = new CSquare();
    pShape = pSquare;
    pShape->draw();//Square

    CTriangle* pTriangle = new CTriangle();
    pShape = pTriangle;
    pShape->draw();//Triangle

    return 0;
}

/*
output:
CShape::draw()
CCircle::draw()
CSquare::draw()
CTriangle::draw()
*/
