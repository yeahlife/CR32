#pragma once
class CBlock
{
public:
    // ö�ٶ�����Գ��ֵ�ͼ����״
    // �����ĸ�����������ң������µ�Ӣ����ĸ���ţ�I��J��L��O��S��T��Z
    enum emBlockType {
        NoShape = 0,    // ��ͼ��
        ZShape,         // Z ����
        SShape,         // S ����
        LineShape,      // I ����
        TShape,         // T ����
        SquareShape,    // O ����
        LShape,         // L ����
        MirroredLShape  // ��L ����
    };
    // ��ʼ������ͼ��
    void Init();

    // ��ȡͼ�� X������
    int X(int Index) {
        return m_coords[Index][0];
    }
    // ��ȡͼ�� Y������
    int Y(int Index) {
        return m_coords[Index][1];
    }

private:
    // �������ֵ�����ѡ������ͼ��
    void SetRandom();
    // ��ȡ���ͼ��
    void SetShape(emBlockType m_Type);

private:
    emBlockType m_Type;
    int m_coords[4][2];
};

