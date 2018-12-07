// TestInherit.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <ctime>

/*
    ���ؼ̳�
    class CChinese : public CPerson

    ���ؼ̳�
    class A : public B, public C

    //ɳ����

*/

//���μ̳� 
//�Ҿ���
class CFurniture {
public:
    CFurniture() {
        printf("CFurniture::CFurniture()\r\n");
        m_nFurniture = 0;
    }

    void use() {};

    int m_nFurniture;

};

//��̳�
class CSofa : virtual public CFurniture{
public:
    CSofa() {
        printf("CSofa::CSofa()\r\n");
        m_nSofa = 1;
    }
    
    virtual void sit() {
        printf("CSofa::sit()\r\n");
    }

private:
    int m_nSofa;
};

class CBed : virtual public CFurniture {
public:
    CBed() {
        printf("CBed::CBed()\r\n");
        m_nBed = 2;
    }

    void sleep() {
        printf("CBed::sleep()\r\n");
    }

private:
    int m_nBed;
};

//ɳ�������ؼ̳� ���ȼ̳���ɳ�����ص㣬�ּ̳��˴����ص�
class CSofaBed : public CSofa, public CBed {
public:
    CSofaBed() {
        printf("CSofaBed::CSofaBed()\r\n");
        m_nSofaBed = 3;
    }

private:
    int m_nSofaBed;
};


/*
    1. ���ؼ̳����麯��
    2. ������̳����麯��
    3. ���ؼ̳����麯��
    4. ������̳����麯��

    1. ���ؼ̳����麯��
    2. ������̳����麯��
    3. ���ؼ̳����麯��
    4. ������̳����麯��

    ���μ̳�
*/


int main()
{
    CSofa sofa;
    int sofaSize = sizeof(CSofa);

    CSofaBed sofaBed;
    
    ////��Ƭ
    CSofa* pSofa = &sofaBed;
    CBed* pBed = &sofaBed;


    CFurniture* pFur = &sofaBed;
    //CFurniture* pFur2 = &sofaBed;
    sofaBed.m_nFurniture = 1;

    int nSize = sizeof(CSofaBed);

    //sofaBed.CSofa::m_nFurniture = 1;
    //sofaBed.CBed::m_nFurniture = 1;
    //sofaBed.sit();

    //sofaBed.sleep();

    ////��Ƭ
    //CSofa* pSofa = &sofaBed;
    //CBed* pBed = &sofaBed;

    return 0;
}

