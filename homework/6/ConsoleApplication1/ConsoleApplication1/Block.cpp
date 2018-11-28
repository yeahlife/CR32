#include "stdafx.h"
#include "Block.h"
#include <stdlib.h>

// ��ʼ������ͼ��
void CBlock::Init()
{
    SetRandom();
    SetShape(m_Type);
}

// �������ֵ�����ѡ������ͼ��
void CBlock::SetRandom()
{
    // �� 1-7�������ѡ��ͼ��
    m_Type = (emBlockType)(rand() % 7 + 1);
}
// ��ȡ���ͼ��
void CBlock::SetShape(emBlockType m_Type)
{
    // ʹ����������ʾͼ��
    static const int coordsTable[8][4][2] = {
        { { 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 } },     // ��ͼ��
        { { 0, -1 },{ 0, 0 },{ -1, 0 },{ -1, 1 } },  // Z ����
        { { 0, -1 },{ 0, 0 },{ 1, 0 },{ 1, 1 } },    // S ����
        { { 0, -1 },{ 0, 0 },{ 0, 1 },{ 0, 2 } },    // I ����
        { { -1, 0 },{ 0, 0 },{ 1, 0 },{ 0, 1 } },    // T ����
        { { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } },     // O ����
        { { -1, -1 },{ 0, -1 },{ 0, 0 },{ 0, 1 } },  // L ����
        { { 1, -1 },{ 0, -1 },{ 0, 0 },{ 0, 1 } }    // ��L ����
    };

    // �������ֵ����ͼ���ó���
    for (int i = 0; i < 4; i++) {
        m_coords[i][0] = coordsTable[m_Type][i][0];
        m_coords[i][1] = coordsTable[m_Type][i][1];
    }
}