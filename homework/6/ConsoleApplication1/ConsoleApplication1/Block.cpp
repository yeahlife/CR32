#include "stdafx.h"
#include "Block.h"
#include <stdlib.h>

// 初始化方块图案
void CBlock::Init()
{
    SetRandom();
    SetShape(m_Type);
}

// 产生随机值，随机选择哪种图案
void CBlock::SetRandom()
{
    // 从 1-7里面随机选择图案
    m_Type = (emBlockType)(rand() % 7 + 1);
}
// 获取随机图案
void CBlock::SetShape(emBlockType m_Type)
{
    // 使用坐标来表示图案
    static const int coordsTable[8][4][2] = {
        { { 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 } },     // 无图案
        { { 0, -1 },{ 0, 0 },{ -1, 0 },{ -1, 1 } },  // Z 字形
        { { 0, -1 },{ 0, 0 },{ 1, 0 },{ 1, 1 } },    // S 字形
        { { 0, -1 },{ 0, 0 },{ 0, 1 },{ 0, 2 } },    // I 字形
        { { -1, 0 },{ 0, 0 },{ 1, 0 },{ 0, 1 } },    // T 字形
        { { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } },     // O 字形
        { { -1, -1 },{ 0, -1 },{ 0, 0 },{ 0, 1 } },  // L 字形
        { { 1, -1 },{ 0, -1 },{ 0, 0 },{ 0, 1 } }    // 反L 字形
    };

    // 根据随机值，把图案拿出来
    for (int i = 0; i < 4; i++) {
        m_coords[i][0] = coordsTable[m_Type][i][0];
        m_coords[i][1] = coordsTable[m_Type][i][1];
    }
}