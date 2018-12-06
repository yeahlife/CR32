#include "stdafx.h"
#include "Shape.h"


CShape::CShape()
{
}


CShape::~CShape()
{
}

void CShape::draw() {
    printf("CShape::draw()\r\n");
}

void CShape::passRefDisplay(CShape& refShape) {
    refShape.draw();
}
