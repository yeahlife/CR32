// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "setdisplay.h" // ���ڴ��������ͷ�ļ�
#include "Scenes.h" // ���ڽ��������ͷ�ļ�
#include "Block.h"
#include <conio.h>

int main()
{
    // ���ÿ���̨����ʹ���
    srand(time(NULL));
    // 1. ���ÿ���̨����ʹ��ڴ�С
    SetWindowSize("����̨��ɫ��������", // ����
        30, // �߶� 30 �� // ��1920*1080����ʾ�������ֵΪ60
        30  // ��� 30 �� // 1 �� = 1 ������ �� 2 ��Ӣ�� 
    );

    // ��ʼ������
    CScenes scenes;
    scenes.Init();

    CBlock block;

    while (true) {
        int nOffset = 10;

        // ��ӡ����
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

