#pragma once
#include "Shape.h"
class CCircle :
    public CShape
{
public:
    CCircle();
    ~CCircle();

public:
    virtual void draw();
};

