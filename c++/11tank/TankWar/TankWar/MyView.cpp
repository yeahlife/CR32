#include "stdafx.h"
#include "MyView.h"
#include "glut\glut.h"

unsigned char g_mapData[26][26] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
    0x01, 0x01, 0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x00, 0x00, 0x01,  0x01,
    0x02, 0x02, 0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x00, 0x00, 0x02,  0x02,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x00, 0x01, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
};



CMyView::CMyView()
{
    //��pcx�ļ��ּ���̹��ͼƬ�ز�
    CImageBuf ImageBuf;
    ImageBuf.LoadPcx("data\\object.pcx");

    //��ȡש���ݵ�Ԫ��
    for (int i = 1; i <= 5; i++) {
        ImageBuf.CopyImage(0 + (i - 1) * 25, 256, 25, 25, MapPic[i]);
    }

    for (int i = 0; i < 4; i++) {
        ImageBuf.CopyImage(150 + (i + 1) * 50, 50, 50, 49, TankPic[0][i]);             //�����ϡ��¡����ҳ���tank
    }

    for (int i = 0; i < 4; i++) {
        ImageBuf.CopyImage(150 + (i + 1) * 50, 0, 50, 49, TankPic[1][i]);             //�����ϡ��¡����ҳ���tank
    }

    for (int i = 0; i < 4; i++) {
        ImageBuf.CopyImage(0 + (i)* 50, 0, 50, 49, TankPic[2][i]);             //�����ϡ��¡����ҳ���tank
    }

    for (int i = 0; i < 4; i++) {
        ImageBuf.CopyImage(150 + (i + 1) * 50, 201, 50, 49, TankPic[3][i]);             //�����ϡ��¡����ҳ���tank
    }

    for (int i = 0; i <= 5; i++) {
        ImageBuf.CopyImage(50 + i * 50, 150, 50, 50, BoomPic[i]);                       //for boom
    }

    for (int i = 0; i < 2; i++)
    {
        ImageBuf.CopyImage(i * 15, 150, 15, 15, BulletPic[i]);             //�����ϡ��¡����ҳ���tank
    }

    ImageBuf.CopyImage(0, 100, 50, 50, HomeBase);             //�����ϡ��¡����ҳ���tank


                                                              //��ʼ����ǰ������
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            m_mapData[i][j] = g_mapData[i][j];
        }
    }

    m_MyTank.SetCurX(9 * 25);
    m_MyTank.SetCurY(25 * 25);
}


CMyView::~CMyView()
{
}

void CMyView::drawMap() {

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (m_mapData[i][j] == 0x01) {
                DrawElement(j * 25, (25 - i) * 25, m_mapData[i][j]);
            }
            else if (m_mapData[i][j] == 0x02) {
                DrawElement(j * 25, (25 - i) * 25, m_mapData[i][j]);
            }
            else if (m_mapData[i][j] == 0x05) {
                DrawElement(j * 25, (25 - i) * 25, m_mapData[i][j]);
            }
            else if (m_mapData[i][j] == 0x06) {
                DrawHomeBase(j * 25, (25 - i) * 25);
            }
        }
    }

    //��ʼ����̹��
    //DrawTank(nCurTankX * 25, (25 - nCurTankY) * 25, 1, nCurRotate);
    DrawTank(m_MyTank.CurX(),
             (650 - m_MyTank.CurY() - 25),
             m_MyTank.m_nType, 
             m_MyTank.m_nRotate);
}

void CMyView::OnUp()
{
    int nX = (m_MyTank.CurX() + 2) / 25;
    int nY = m_MyTank.CurY() / 25;

    if (!CheckImpact(nX, nY)) {
        m_MyTank.OnUp();
    }
}

void CMyView::OnDown()
{

    m_MyTank.OnDown();
}

void CMyView::OnLeft()
{
    m_MyTank.OnLeft();
}

void CMyView::OnRight()
{
    m_MyTank.OnRight();
}

bool CMyView::CheckImpact(int x, int y) {

    if (x < 0 || x + 1 > 25) {
        return true;
    }

    if (y - 1 < 0 || y > 25) {
        return true;
    }

    if (m_mapData[y][x] != 0x00 ||
        m_mapData[y][x + 1] != 0x00 ||
        m_mapData[y - 1][x] != 0x00 ||
        m_mapData[y - 1][x + 1] != 0x00) {
        return true;
    }

    return false;
}

void MixPic(int x, int y, int w, int h, unsigned char *buf)             //glReadPixels 
{
    int PixelByte = 4;        //for RGBA color

    int SrcTempPos = 0, TempPos = 0;
    unsigned char *Temp = new unsigned char[w*h*PixelByte];

    glReadPixels(x, y, w, h, GL_RGB, GL_UNSIGNED_BYTE, Temp);
    glReadPixels(x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, Temp);
    for (int i = 0; i<w*h; i++)
    {
        if ((buf[SrcTempPos + 3]) == 0)          //�ҳ��˱߿�Ϊ��ɫ�Ĳ���
        {
            memcpy(&buf[SrcTempPos], &Temp[TempPos], 3);         //��ʾ����ɫ
        }
        SrcTempPos += 4;
        TempPos += PixelByte;
    }
    delete[]Temp;
}

//���ƻ���Ԫ�أ� nType = 1 ��ʾש  2 �� 3 ǳ������ 4 �������� 5 �� 
void CMyView::DrawElement(int x, int y, int nType) {
    glRasterPos2i(x, y);      //Ϊ���ز���ָ����դλ��  ��25*i j  Ϊ����ʾͼ��Ĳ��ص�
    MixPic(25, 25, 25, 25, MapPic[nType]);
    glDrawPixels(25, 25, GL_RGBA, GL_UNSIGNED_BYTE, MapPic[nType]);  //��һ�����ؿ�д��֡����  
}

void CMyView::DrawBg(int x, int y) {
    //���ƾ���
    glColor3f(0.0f, 0.0f, 0.0f);
    glRectf(x, y, x+25.0f, y+25.0f);
}

void CMyView::DrawBoom(int x, int y, int nType) {

    glRasterPos2i(x, y);      //Ϊ���ز���ָ����դλ��  ��25*i j  Ϊ����ʾͼ��Ĳ��ص�
    glDrawPixels(50, 50, GL_RGBA, GL_UNSIGNED_BYTE, BoomPic[nType]);  //��һ�����ؿ�д��֡����  
}

void CMyView::DrawTank(int x, int y, int nType, int nRotate) {

    glRasterPos2i(x, y);      //Ϊ���ز���ָ����դλ��  ��25*i j  Ϊ����ʾͼ��Ĳ��ص�
    glDrawPixels(50, 49, GL_RGBA, GL_UNSIGNED_BYTE, TankPic[nType][nRotate]);  //��һ�����ؿ�д��֡����  
}

void CMyView::DrawHomeBase(int x, int y) {

    glRasterPos2i(x, y);      //Ϊ���ز���ָ����դλ��  ��25*i j  Ϊ����ʾͼ��Ĳ��ص�				
    glDrawPixels(50, 50, GL_RGBA, GL_UNSIGNED_BYTE, HomeBase);  //��һ�����ؿ�д��֡����  

}

void CMyView::DrawBullet(int x, int y, int nType) {

    glRasterPos2i(x, y);      //Ϊ���ز���ָ����դλ��  ��25*i j  Ϊ����ʾͼ��Ĳ��ص�
    glDrawPixels(15, 15, GL_RGBA, GL_UNSIGNED_BYTE, BulletPic[nType]);  //��һ�����ؿ�д��֡����  
}
