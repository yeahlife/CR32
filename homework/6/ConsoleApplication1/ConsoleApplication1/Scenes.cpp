#include "stdafx.h"
#include <stdlib.h>
#include "Scenes.h"

void CScenes::Init()
{
    // 游戏场景 宽
    m_nMapWidth = 10;
    // 游戏场景 高
    m_nMapHeight = 20;
    // 保存堆内存空间地址
    m_pMap = (char*)malloc(m_nMapWidth * m_nMapHeight);
    // 初始化墙
    // 1 画做墙 0 为空闲区域
    // 外层Y轴竖着循环为参考，内层X轴横着循环
    for (int i = 0; i < m_nMapHeight; i++){
        for (int j = 0; j < m_nMapWidth; j++) {
            // 判断是否需要画为墙，
            // X轴 第0列 和 最后一列 需要画墙
            // Y轴 最后一行 需要画墙
            if (j == 0 || j == m_nMapWidth - 1 || i == m_nMapHeight - 1) {
                m_pMap[i*m_nMapWidth + j] = 1; // i*m_nMapWidth + j 内存矩阵排列存储
            }
            else {
                m_pMap[i*m_nMapWidth + j] = 0;
            }
        }
    }
    // 初始化方块
    m_Block.Init();
    // 绘制背景到控制台
    DrawBg();
}

// 绘制背景到控制台
void CScenes::DrawBg()
{
    // 外层Y轴竖着循环为参考，内层X轴横着循环
    for (int i = 0; i < m_nMapHeight; i++) {
        for (int j = 0; j < m_nMapWidth; j++) {
            if (m_pMap[i*m_nMapWidth + j] == 0) {
                // 0 显示背景
                ShowBg(i, j);
            }
            else if(m_pMap[i*m_nMapWidth + j] == 1){
                // 1 显示墙或方块
                ShowBlock(i, j);
            }
        }
    }
}

void CScenes::ShowBlock(int x, int y)
{
    WriteChar(x,  // 第 1 行
        y,  // 第 1 列
        "■",
        SetConsoleColor(COLOR_BLUE, // 
            COLOR_BLACK)  // 白色背景
    );
}

//绘制背景
void CScenes::ShowBg(int x, int y) {
    WriteChar(x,  // 第 1 行
        y,  // 第 1 列
        "  ",
        SetConsoleColor(COLOR_BLACK, // 黑色前景
            COLOR_WHITE)  // 白色背景
    );
}