#pragma once
class CBlock
{
public:
    // 枚举定义可以出现的图案形状
    // 各种四格骨牌由左至右，上至下的英文字母代号：I、J、L、O、S、T、Z
    enum emBlockType {
        NoShape = 0,    // 无图形
        ZShape,         // Z 字形
        SShape,         // S 字形
        LineShape,      // I 字形
        TShape,         // T 字形
        SquareShape,    // O 字形
        LShape,         // L 字形
        MirroredLShape  // 反L 字形
    };
    // 初始化方块图案
    void Init();

    // 获取图案 X轴坐标
    int X(int Index) {
        return m_coords[Index][0];
    }
    // 获取图案 Y轴坐标
    int Y(int Index) {
        return m_coords[Index][1];
    }

private:
    // 产生随机值，随机选择哪种图案
    void SetRandom();
    // 获取随机图案
    void SetShape(emBlockType m_Type);

private:
    emBlockType m_Type;
    int m_coords[4][2];
};

