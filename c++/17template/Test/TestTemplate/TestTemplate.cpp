// TestTemplate.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
//ģ��
// template
// 1. ����ģ��
// 2. ��ģ��

//int GetMax(int a, int b) {
//    return a > b ? a : b;
//}

//double GetMax(double a, double b) {
//    return a > b ? a : b;
//}

//����ģ��
template<typename T>
T GetMax(T a, T b) {
    //1asdfsadfsadf;
    return a > b ? a : b;
}


template<typename T = int, int SIZE = 100>
T Test(T a, T b) {
    //1asdfsadfsadf;
    int n = SIZE;
    return a > b ? a : b;
}
//const char* GetMax(const char* a, const char* b) {
//    //1asdfsadfsadf;
//    int nA = strlen(a);
//    int nB = strlen(b);
//    return nA > nB ? a : b;
//}

//ģ������
template<>
const char* GetMax(const char* a, const char* b) {
    //1asdfsadfsadf;
    int nA = strlen(a);
    int nB = strlen(b);
    return nA > nB ? a : b;
}

//int test(int a, float f) {
//    return a;
//}
//
//float test(int a, float f) {
//    return a;
//}

//template<typename T1, typename T2>
//T1 GetMax(T1 a, T2 b) {
//    return a;
//}

int main()
{
    Test(1, 2);

    //��ʽʵ����ģ��
    //int n = GetMax(1.0f, 2.0f);
    //int n = GetMax(1, 2.0f); ������

    //��ʽʵ����ģ��
    //n = GetMax<int>(1, 2.0f);
    const char* p = GetMax("abc", "1234");
    //GetMax<int, float>(1, 2.0f);

    //ģ������/�ػ�

    return 0;
}

