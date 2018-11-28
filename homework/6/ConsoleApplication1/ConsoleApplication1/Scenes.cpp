#include "stdafx.h"
#include <stdlib.h>
#include "Scenes.h"

void CScenes::Init()
{
    // ��Ϸ���� ��
    m_nMapWidth = 10;
    // ��Ϸ���� ��
    m_nMapHeight = 20;
    // ������ڴ�ռ��ַ
    m_pMap = (char*)malloc(m_nMapWidth * m_nMapHeight);
    // ��ʼ��ǽ
    // 1 ����ǽ 0 Ϊ��������
    // ���Y������ѭ��Ϊ�ο����ڲ�X�����ѭ��
    for (int i = 0; i < m_nMapHeight; i++){
        for (int j = 0; j < m_nMapWidth; j++) {
            // �ж��Ƿ���Ҫ��Ϊǽ��
            // X�� ��0�� �� ���һ�� ��Ҫ��ǽ
            // Y�� ���һ�� ��Ҫ��ǽ
            if (j == 0 || j == m_nMapWidth - 1 || i == m_nMapHeight - 1) {
                m_pMap[i*m_nMapWidth + j] = 1; // i*m_nMapWidth + j �ڴ�������д洢
            }
            else {
                m_pMap[i*m_nMapWidth + j] = 0;
            }
        }
    }
    // ��ʼ������
    m_Block.Init();
    // ���Ʊ���������̨
    DrawBg();
}

// ���Ʊ���������̨
void CScenes::DrawBg()
{
    // ���Y������ѭ��Ϊ�ο����ڲ�X�����ѭ��
    for (int i = 0; i < m_nMapHeight; i++) {
        for (int j = 0; j < m_nMapWidth; j++) {
            if (m_pMap[i*m_nMapWidth + j] == 0) {
                // 0 ��ʾ����
                ShowBg(i, j);
            }
            else if(m_pMap[i*m_nMapWidth + j] == 1){
                // 1 ��ʾǽ�򷽿�
                ShowBlock(i, j);
            }
        }
    }
}

void CScenes::ShowBlock(int x, int y)
{
    WriteChar(x,  // �� 1 ��
        y,  // �� 1 ��
        "��",
        SetConsoleColor(COLOR_BLUE, // 
            COLOR_BLACK)  // ��ɫ����
    );
}

//���Ʊ���
void CScenes::ShowBg(int x, int y) {
    WriteChar(x,  // �� 1 ��
        y,  // �� 1 ��
        "  ",
        SetConsoleColor(COLOR_BLACK, // ��ɫǰ��
            COLOR_WHITE)  // ��ɫ����
    );
}