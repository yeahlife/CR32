#ifndef SCORE_H
#define SCORE_H
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Score{
    string player;
    int score;
	

public:
    Score(){player = "Test";score = 0;};//��ʼ��״̬��Ϣ
    void setName(string name){player = name;};//��������
    void setScore(int s){score = s;};//���÷���

    void printMessage();//��ӡ��Ϣ
};

#endif
