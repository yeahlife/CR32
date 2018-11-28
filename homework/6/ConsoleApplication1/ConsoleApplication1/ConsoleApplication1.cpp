// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "setdisplay.h" // 用于创建界面的头文件
#include "Scenes.h" // 用于界面操作的头文件
#include "Block.h"
#include <conio.h>

int main()
{
    // 设置控制台标题和窗口
    srand(time(NULL));
    // 1. 设置控制台标题和窗口大小
    SetWindowSize("控制台颜色测试用例", // 标题
        30, // 高度 30 行 // 在1920*1080的显示器中最大值为60
        30  // 宽度 30 列 // 1 列 = 1 个汉字 或 2 个英文 
    );

    // 初始化界面
    CScenes scenes;
    scenes.Init();

    CBlock block;

    while (true) {
        int nOffset = 10;

        // 打印方块
        for (int i = 0; i < 4; i++) {
            scenes.ShowBlock(block.X(i) + nOffset, block.Y(i) + nOffset);
        }

        if (_kbhit()) {
            char ch;
            ch = _getch();


            /*  clearBg();
            if (ch == 'a') {
            block.LeftRotate();

            }
            else if (ch == 'd') {
            block.RightRotate();
            }*/
        }

    }
    return 0;
}

