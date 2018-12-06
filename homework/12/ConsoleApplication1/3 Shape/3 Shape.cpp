/*
3.
����Ŀ2�Ļ����Ͻ�һ����
����һ��ͨ����ֵ��ʽ����Shape��������ĺ�����
��������������ת��һ�������������Ϊ������
���������Ρ�
ͨ���Ѳ�����ΪShape������������޸����������

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


