#pragma once

class tagTest
{   
public:
    // ����
    int n1;

    // ��Ϊ
    int __stdcall SetN1(int n1);
    int __stdcall GetN1();
protected:
    // ����
    int n2;

    // ��Ϊ
    int __stdcall SetN2(int n2);
    int __stdcall GetN2();
private:
    // ����
    int n3;

    // ��Ϊ
    int __stdcall SetN3(int n3);
    int __stdcall GetN3();
};
