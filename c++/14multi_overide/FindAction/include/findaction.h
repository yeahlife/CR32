#pragma once

// ��ͼ��С
#define MAPROW  31  // ��
#define MAPCOL  28  // ��

class CPostion;

/*
* Ѱ·�㷨
* 
* eg: FindAction(pMap, (5, 5), (10, 10), pCrashElement, 2);
*
* pMap:             ��ͼ��ά����ָ��
* srcPos:           ��ʼ����
* dstPos:           Ŀ������
* pCarshElement:    �ᷢ����ײԪ�ص�����
* nCarshElementNum: ����Ԫ�ظ�����Ĭ��Ϊ1��
*
* ע���ڳԶ�����Ϸģʽ�ж��ڹ���ԣ�
*     ֻ��ǽ�ǲ��ɴ�Խ�ģ�
*     ��Ϊ���㷨�Ŀ���չ�Բ������������ʽ��
*     �Ӷ�ʵ�ֵ�ͼ�������µĹ��ɴ�ԽԪ��
*     �㷨�����޸ĵ�Ŀ�ġ�
*     ��ʵҲ���Բ���λ����ķ�ʽ��
*     �������Ե�ͼԪ�ض�����Ҫ��
*     ���Բ����á�
*
*     ���ڴ���Ŀ������Ϸ��Լ�飬
*     �ڴ���Ŀ�����겻�Ϸ�������£�
*     Ĭ�Ͻ�Ŀ�������ƶ�һ���ڳԶ��˵�ͼ�в����д���
*     Ҳ�ɸ���������ʵ�ִ����е���Ϊ���� -1 ������������
*/
int FindAction(const int (*pMap)[MAPCOL] ,
               CPostion srcPos ,
               CPostion dstPos ,
               int *pCrashElement ,
               int nCrashElementNum = 1
               );

// ����
enum emAction
{
  actUp = 0,
  actDown,
  actLeft,
  actRight
};


// x, y �����
enum emPostion
{
  posRow = 0,
  posCol
};

// �����࣬���ڼ�Ѱ·�㷨
class CPostion
{
public:
  CPostion();
  CPostion(int nRow , int nCol);
  CPostion(CPostion& obj);
  ~CPostion();
  // ��ȡ��Ӧ��������
  int& operator[](int nIndex);
  // ���긳ֵ
  CPostion& operator=(CPostion& obj);
  // ������������ӣ�ֱ����ӣ�
  CPostion operator+(CPostion& obj);
  // ��ȡ������������������Ĳ�����Ǹ�ֵ��
  CPostion operator-(CPostion& obj);
  // ���������������
  CPostion operator*(int nNum);
  // �ж������Ƿ����
  int operator==(CPostion& obj);
  int operator!=(CPostion& obj);
  // �������꣨��ֹԽ�磩
  void amend();
  // ��������
  void set(int nRow , int nCol);
  // ��ȡ��������¸�����
  CPostion getActionPostion(int nAction);
  // ���ݷ����޸�����
  void changePostion(int nAction);

private:
  int m_nRow;
  int m_nCol;
};


/*
* �򵥵���ײ���
* nMapElement:      ��ͼ�ϵ�Ԫ��
* pCarshElement:    �ᷢ����ײԪ�ص�����
* nCarshElementNum: ����Ԫ�ظ���
*
* ע���ڳԶ�����Ϸģʽ�ж��ڹ���ԣ�
*     ֻ��ǽ�ǲ��ɴ�Խ�ģ�
*     ��Ϊ���㷨�Ŀ���չ�Բ������������ʽ��
*     �Ӷ�ʵ�ֵ�ͼ�������µĹ��ɴ�ԽԪ��
*     �㷨�����޸ĵ�Ŀ�ġ�
*     ��ʵҲ���Բ���λ����ķ�ʽ��
*     �������Ե�ͼԪ�ض�����Ҫ��
*     ���Բ����á�
*/
bool ThisPointIsCarsh(int nMapElement ,
                      int* pCarshElement ,
                      int nCarshElementNum);