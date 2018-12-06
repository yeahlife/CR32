#pragma once
class CShape
{
public:
    CShape();
    ~CShape();

public:
    virtual void draw();
    void passRefDisplay(CShape& refShape);
};

