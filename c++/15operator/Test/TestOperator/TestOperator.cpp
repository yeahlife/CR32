#include "stdafx.h"
#include <graphics.h>
#include <conio.h>

int main()
{
    // ��ʼ����ͼ����
    initgraph(640, 480);

    loadimage(NULL, _T("G:\\123.jpg"));

    // ��ȡָ���Դ��ָ��
    //DWORD* pMem = GetImageBuffer();

    // ��������˳�
    _getch();
    closegraph();
}