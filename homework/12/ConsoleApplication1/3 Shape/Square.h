#pragma once
#include "Shape.h"
class CSquare :
    public CShape
{
public:
    CSquare();
    ~CSquare();

public:
    virtual void draw();
};

