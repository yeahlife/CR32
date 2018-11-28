#pragma once
#include "setdisplay.h"
#include "Block.h"

class CScenes
{
public:
    // 初始化界面
    void Init();
    // 绘制背景到控制台
    void DrawBg();
    // 显示方块
    void ShowBlock(int x, int y);
    // 显示背景
    void ShowBg(int x, int y);

private:
    // 游戏场景 宽
    int m_nMapWidth;
    // 游戏场景 高
    int m_nMapHeight;
    // 还需要一个变量来保存这个申请的空间大小，动态申请的堆内存，需要用一个指针变量保存合适点
    char* m_pMap;
    //方块类
    CBlock m_Block;
};

