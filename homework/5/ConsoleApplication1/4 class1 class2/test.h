#pragma once

class tagA;
class tagB;

class tagA
{   
public:
    void ShowA();
    // tagA::b����һ��tagB*���͵�ָ��
    tagB* b; 
};

class tagB
{
public:
    void ShowB();
    // tagB::a����һ��tagA*���͵�ָ��
    tagA* a;
};