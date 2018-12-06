#pragma once
#include "Shape.h"
class CTriangle :
    public CShape
{
public:
    CTriangle();
    ~CTriangle();

public:
    virtual void draw();
};

