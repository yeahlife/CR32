#pragma once

class tagTest
{   
public:
    // 数据
    int n1;

    // 行为
    int __stdcall SetN1(int n1);
    int __stdcall GetN1();
protected:
    // 数据
    int n2;

    // 行为
    int __stdcall SetN2(int n2);
    int __stdcall GetN2();
private:
    // 数据
    int n3;

    // 行为
    int __stdcall SetN3(int n3);
    int __stdcall GetN3();
};
