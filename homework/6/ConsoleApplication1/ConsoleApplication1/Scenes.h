#pragma once
#include "setdisplay.h"
#include "Block.h"

class CScenes
{
public:
    // ��ʼ������
    void Init();
    // ���Ʊ���������̨
    void DrawBg();
    // ��ʾ����
    void ShowBlock(int x, int y);
    // ��ʾ����
    void ShowBg(int x, int y);

private:
    // ��Ϸ���� ��
    int m_nMapWidth;
    // ��Ϸ���� ��
    int m_nMapHeight;
    // ����Ҫһ�������������������Ŀռ��С����̬����Ķ��ڴ棬��Ҫ��һ��ָ�����������ʵ�
    char* m_pMap;
    //������
    CBlock m_Block;
};

