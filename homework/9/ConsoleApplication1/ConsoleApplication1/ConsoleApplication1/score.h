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
    Score(){player = "Test";score = 0;};//初始化状态信息
    void setName(string name){player = name;};//设置名字
    void setScore(int s){score = s;};//设置分数

    void printMessage();//打印信息
};

#endif
