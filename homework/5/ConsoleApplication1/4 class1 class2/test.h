#pragma once

class tagA;
class tagB;

class tagA
{   
public:
    void ShowA();
    // tagA::b就是一个tagB*类型的指针
    tagB* b; 
};

class tagB
{
public:
    void ShowB();
    // tagB::a就是一个tagA*类型的指针
    tagA* a;
};