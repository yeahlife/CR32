#include "stdafx.h"
#include "score.h"
#include "cur.h"
#include "cubePoint.h"

void Score::printMessage()//��ӡ��Ϣ
{
   Cur c;      //������
   CubePoint p;//������

   p.setLocate(2,19);//����λ��
   p.setColor(WHITE);//������ɫ
   p.printPoint();//? ��ӡ�����
   
   c.saveCur();//���������
   c.moveCur(2,21);//�ƶ������
   cout<<"player: "<<player;//��ӡ�����Ϣ
   c.resumeCur();//�ָ�����

   p.setLocate(4,19);//����λ��
   p.setColor(GREEN);//������ɫ
   p.printPoint();//? ��ӡ�����

   c.saveCur();//���������
   c.moveCur(4,21);//�ƶ������
   cout<<"score : "<<score;//��ӡ������Ϣ
   c.resumeCur();//�ָ�����

}
