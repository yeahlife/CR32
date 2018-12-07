#include "findaction.h"

/**************************************************
* Ѱ·�㷨 - ������������㷨����ҳϵ��㷨��
*
* ���㷨���ڶ��㵽�����Ѱ·��
* ��һ��ʵʱ�㷨��ÿ��ֻ�ܻ�ȡ��һ�������Ǹ������ߡ�
*
* ���������㷨��Ŀ����Ϊ��֪����һ�������Ǹ������ߣ�
* �������еĲ�����Χ�Ʊ�����ȷ�ķ���Ϊ����
* ���Ҳ����Ҫ�����߹���·����
* 
* ��С�����ӵĵ�ͼ�ϣ�
* ����㷨��Ч����ԶԶ���� A-Star �㷨��
* ��Ϊ A-Star �㷨�����ڶ��㵽�����Ѱ·��
* ������Ѱ·�����в��ϱ�������·����
* ��δ󲿷��������� A-Star �㷨���ǲ��õݹ鷽��ʵ�֣�
* ��Ч�����кܴ����⣬
* �����㷨��ʵ�ֲ��õ��ǵ����ķ�ʽ��
* ����ڳԶ��������Ϸ�����У����㷨���Ƹ���
*
* ���㷨ȱ�㣺
*     �������һ�������ܵ����Ŀ��㣨������ǽΧס�ĵ㣩��
*     �ͻ���ѭ����
*
* ���Ч��ʹ�÷�����
*     �ڳԶ��˵���Ϸģʽ�У���ֻ����·��ʱ�Ż�ı䷽��
*     ��ˣ�ֻ��·�ڵ��ø��㷨����÷����ʹ��ϷЧ�����
*     ����һ����ʵ���⣺ÿ��·�ڵ���ʱ�������Ŀ�������
*     ������ǳ��ǳ�ϸ΢�Ŀ��ٸУ�����Ҫȡ����������
*     ��Ϸ�߼�����Ƶĳɹ���û�п��ٸе�
**************************************************/


/******************* �㷨α���� ********************
// �㷨��Ҫ�߼���ʡ���˺Ϸ��Լ�顢�ƶ����ꡢ��ײ����
���� FindAction(x0, y0, x1, y1){
		int ���ŷ��� = NONE
		�ȼ�¼ԭ��Ŀ��,x0, y0
		while(true){
			��������{
				if(��λ��Ŀ��){
					return ����
				}
				else if(�������ƶ�){
					�¸�״̬��ӽ�״̬ 
				}else if(�������ƶ�){
					�¸�״̬��ӽ�״̬
				}else if(�������ƶ�){
					�¸�״̬��ӽ�״̬
				}else if(�������ƶ�){
					����һ��״̬��ӽ�״̬��
				}
			}
		}
}
**************************************************/



/***************** Ѱ·�㷨ʵ�� *******************/


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
               int *pCrashElement,
               int nCrashElementNum
               )
{
  
  // �жϴ��������Ƿ���ȷ
  while(true)
  {
    // ���������ݺϷ���
    dstPos.amend();
    // ���Ŀ�������Ƿ�����һ���ܹ�����ĵ�
    if(ThisPointIsCarsh((pMap[ dstPos[ emPostion::posRow ] ][ dstPos[ emPostion::posCol ] ]) ,
                        pCrashElement,
                        nCrashElementNum
                       )
       )
    {
      /*************** ���ִ��������ɸ���������� ***************/
      // �����ǽ�ͽ����������·��ƶ�һ�������жϣ�
      // ��Ϊ�ڳԶ��˵�ͼ��ÿһ�������ٻ���һ��λ�ò���ǽ��
      dstPos = dstPos.getActionPostion(emAction::actDown);
      // ��һ�ִ����������� -1
      // return -1;
    }
    else
    {
      break;
    }
  }

  // ��ͼ���飬���ڱ����߹���·
  int nPassPostion[ MAPROW ][ MAPCOL ] = { 0 };

  // Ѱ·״̬���ṹ�壬���ﲻ��CPostion�����ˣ�Ӱ��Ч��
  typedef struct FindState
  {
    CPostion Pos;
    enum emAction myAction;
    enum emAction firstAction;
  } FindState;

  // ����״̬������飬���ڱ���Ѱַ��Ϣ
  FindState* nowStateArr = new FindState[ 300 ];
  FindState* preStateArr = new FindState[ 300 ];
  FindState* pTempArr;
  // ���������±�
  int nNowArrCur = -1;
  int nPreArrCur = -1;

  // ��ʱ����
  int nTempRow = 0;
  int nTempCol = 0;

  // ��ʼ������Ϣ
  ++nPreArrCur;
  preStateArr[ nPreArrCur ].Pos = srcPos;
  preStateArr[ nPreArrCur ].myAction = emAction::actUp;
  preStateArr[ nPreArrCur ].firstAction = emAction::actUp;
  nPassPostion[ srcPos[ emPostion::posRow ] ][ srcPos[ emPostion::posCol ] ] = 1;

  int nFindNum = 0;

  CPostion tempPos;
  CPostion savePos;
  int nNewRow = 0;
  int nNewCol = 0;
  int nRet = 0;
  while(true)
  {
    // �ж��Ƿ񵽴�Ŀ�������
    for(int i = 0; i <= nPreArrCur; ++i)
    {
      tempPos = preStateArr[ i ].Pos;
      if(tempPos == dstPos)
      {
        nRet = preStateArr[ i ].firstAction;
        delete[] nowStateArr;
        delete[] preStateArr;
        return nRet;
      }
    }

    ++nFindNum;
    // �ӵ�ǰ״̬����Ѱ��
    for(int i = 0; i <= nPreArrCur && nPreArrCur >= 0; ++i)
    {
      // ��ȡ״̬����ֵ
      savePos = preStateArr[ i ].Pos;
      
      // �����ĸ�����
      for(int j = emAction::actUp; j <= emAction::actRight; ++j)
      {
        // ��ȡ״̬����ֵ
        tempPos = savePos;
        // �жϸ������Ƿ��ͨ��
        nTempRow = tempPos.getActionPostion(j)[ emPostion::posRow ];
        nTempCol = tempPos.getActionPostion(j)[ emPostion::posCol ];
        if(ThisPointIsCarsh((pMap[ nTempRow ][ nTempCol ]) ,
                            pCrashElement,
                            nCrashElementNum
                           )
          )
        {
          // ���ܳ��÷����ƶ�
          continue;
        }

        // �����ƶ�������������Ϣ
        tempPos = tempPos.getActionPostion(j);
        // ��ȡ�ƶ����������
        nNewRow = tempPos[ emPostion::posRow ];
        nNewCol = tempPos[ emPostion::posCol ];

        // ���״�
        if(nFindNum > 1 && nPassPostion[ nNewRow ][ nNewCol ] == 0)
        {
          ++nNowArrCur;
          nowStateArr[ nNowArrCur ].Pos = tempPos;
          nowStateArr[ nNowArrCur ].myAction = (emAction)j;
          // �ؼ�����һ��������ǰһ״̬�м�¼�ĳ�ʼ����
          nowStateArr[ nNowArrCur ].firstAction = preStateArr[i].firstAction;
          nPassPostion[ nNewRow ][ nNewCol ] = nFindNum;

        }
        // �״�
        else if(nFindNum == 1 && nPassPostion[ nNewRow ][ nNewCol ] == 0)
        {
          ++nNowArrCur;
          nowStateArr[ nNowArrCur ].Pos = tempPos;
          nowStateArr[ nNowArrCur ].myAction = (emAction)j;
          nowStateArr[ nNowArrCur ].firstAction = (emAction)j;
          nPassPostion[ nNewRow ][ nNewCol ] = nFindNum;
        }
      }
    }

    // ����Ѱַ״̬����ָ����ָ�ռ䣬�Ӷ����浱ǰ״̬������֮ǰ��״̬
    pTempArr = preStateArr;
    preStateArr = nowStateArr;
    nowStateArr = pTempArr;
    // ���������±�
    nPreArrCur = nNowArrCur;
    nNowArrCur = -1;
  }
}




/******************** ������ʵ�� **********************/

CPostion::CPostion()
  : m_nRow(0) , m_nCol(0)
{
}

CPostion::CPostion(int nRow , int nCol)
  : m_nRow(nRow) , m_nCol(nCol)
{

}

CPostion::CPostion(CPostion& obj)
{
  m_nRow = obj.m_nRow;
  m_nCol = obj.m_nCol;
}

CPostion::~CPostion()
{
}

// ��ȡ��Ӧ��������
int& CPostion::operator[](int nIndex)
{
  return (nIndex == emPostion::posRow) ? m_nRow : m_nCol;
}


// ���긳ֵ
CPostion& CPostion::operator=(CPostion& obj)
{
  m_nRow = obj.m_nRow;
  m_nCol = obj.m_nCol;
  return *this;
}


// �ж������Ƿ����
int CPostion::operator==(CPostion& obj)
{
  if(m_nRow == obj.m_nRow)
  {
    if(m_nCol == obj.m_nCol)
    {
      return 1;
    }
  }
  return 0;
}
int CPostion::operator!=(CPostion& obj)
{
  return !(*this == obj);
}

// ������������ӣ�ֱ����ӣ�
CPostion CPostion::operator+(CPostion& obj)
{
  CPostion tempPos = *this;
  tempPos.m_nRow += obj.m_nRow;
  tempPos.m_nCol += obj.m_nCol;
  tempPos.amend();
  return tempPos;
}

// ��ȡ������������������Ĳ�����Ǹ�ֵ��
CPostion CPostion::operator-(CPostion& obj)
{
  CPostion tempPos = *this;
  tempPos.m_nRow -= obj.m_nRow;
  tempPos.m_nCol -= obj.m_nCol;
  return tempPos;
}

// ���������������
CPostion CPostion::operator*(int nNum)
{
  CPostion tempPos = *this;
  tempPos.m_nRow *= nNum;
  tempPos.m_nCol *= nNum;
  return tempPos;
}

// �������꣨��ֹԽ�磩
void CPostion::amend()
{
  m_nRow = (m_nRow + MAPROW) % MAPROW;
  m_nCol = (m_nCol + MAPCOL) % MAPCOL;
}

// ��������
void CPostion::set(int nRow , int nCol)
{
  m_nRow = nRow;
  m_nCol = nCol;

  amend();
}


// ��ȡ��������¸�����
CPostion CPostion::getActionPostion(int nAction)
{
  CPostion nextPos = *this;
  // ����Ԫ��Rowλ��
  nextPos[ emPostion::posRow ] += ((2 & nAction) != 0) ? 0 :
    (((1 & nAction) == 0) ? -1 : 1);

  // ����Ԫ��Colλ��
  nextPos[ emPostion::posCol ] += ((2 & nAction) == 0) ? 0 :
    (((1 & nAction) == 0) ? -1 : 1);

  nextPos[ emPostion::posRow ] += (nextPos[ emPostion::posRow ] < 0) ? MAPROW : 0;
  nextPos[ emPostion::posCol ] += (nextPos[ emPostion::posCol ] < 0) ? MAPCOL : 0;

  nextPos.amend();

  return nextPos;
}

// ���ݷ����޸�����
void CPostion::changePostion(int nAction)
{
  *this = getActionPostion(nAction);
}


/*
* �򵥵���ײ���
* nMapElement:      ��ͼ�ϵ�Ԫ��
* pCarshElement:    �ᷢ����ײԪ�ص�����
* nCarshElementNum: ����Ԫ�ظ���
*
* ע���ڳԶ�����Ϸģʽ�ж��ڹ���ԣ�
      ֻ��ǽ�ǲ��ɴ�Խ�ģ�
      ��Ϊ���㷨�Ŀ���չ�Բ������������ʽ��
      �Ӷ�ʵ�ֵ�ͼ�������µĹ��ɴ�ԽԪ��
      �㷨�����޸ĵ�Ŀ�ġ�
      ��ʵҲ���Բ���λ����ķ�ʽ��
      �������Ե�ͼԪ�ض�����Ҫ��
      ���Բ����á�
*/
bool ThisPointIsCarsh(int nMapElement ,
                      int* pCarshElement ,
                      int nCarshElementNum)
{
  for(int i = 0; i < nCarshElementNum; ++i)
  {
    if(nMapElement == *(pCarshElement + i))
    {
      return true;
    }
  }

  return false;
}
