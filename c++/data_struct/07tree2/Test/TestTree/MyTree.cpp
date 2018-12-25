#include "stdafx.h"
#include "MyTree.h"
#include <queue>
#include <stack>

CMyTree::CMyTree(){

    m_pRoot = nullptr;
    m_nSize = 0;
}


CMyTree::~CMyTree()
{
}

/*
        50
      45  55
*/

void CMyTree::Insert(int data){
    CMyTreeNode* pNew = new CMyTreeNode(data);

    if (m_nSize == 0) {
        m_pRoot = pNew;
        m_nSize++;
        return;
    }

    CMyTreeNode* pCurNode = m_pRoot;

    //表示往左边插入数据
    while (true) {
        
        if (pCurNode->m_data > data) {
            //选择左边
            if (pCurNode->m_pLeft == nullptr){
                pCurNode->m_pLeft = pNew;
                pNew->m_pParent = pCurNode;
                break;
            }
            else {
                pCurNode = pCurNode->m_pLeft;
            }

        }
        else if (pCurNode->m_data < data) {
            //选择右边
            if (pCurNode->m_pRight == nullptr) {
                pCurNode->m_pRight = pNew;
                pNew->m_pParent = pCurNode;
                break;
            }
            else {
                pCurNode = pCurNode->m_pRight;
            }
        }
        else {
            //表示等于
            while (pCurNode->m_pNext != nullptr) {
                pCurNode = pCurNode->m_pNext;
            }

            //pCurNode->m_pNext  == nullptr
            pCurNode->m_pNext = pNew;
            break;
        }
    }

    m_nSize++;
    return;
}

bool CMyTree::Delete(int data)
{
    CMyTreeNode * pFind = Find(data);
    if (pFind == nullptr) {
        return false;
    }

    return Delete(pFind);
}


/*
          50
      45      75
    30    55       80
        53  60  78    90
                  79              
          50
            75
          55

          
*/ 
bool CMyTree::Delete(CMyTreeNode * pNode)
{
    if (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr) {
        //没有儿子

        if (pNode->m_pParent == nullptr) {
            m_pRoot = nullptr;
        }
        else {
            if (pNode->m_pParent->m_pLeft == pNode) {
                pNode->m_pParent->m_pLeft = nullptr;
            }
            else {
                pNode->m_pParent->m_pRight = nullptr;
            }
        }

        delete pNode;
        m_nSize--;
    }
    else if (pNode->m_pLeft != nullptr && pNode->m_pRight != nullptr) {
        //有两儿子
        CMyTreeNode* pCur = pNode->m_pRight;
        while (pCur->m_pLeft != nullptr) {
            pCur = pCur->m_pLeft;
        }

        pNode->m_data = pCur->m_data;
        Delete(pCur);
    }
    else {
        //有一个儿子

        if (pNode->m_pLeft != nullptr) {
            //表示只有左儿子
            if (pNode->m_pParent != nullptr) {
                if (pNode->m_pParent->m_pLeft == pNode) {
                    pNode->m_pParent->m_pLeft = pNode->m_pLeft;
                }
                else {
                    pNode->m_pParent->m_pRight = pNode->m_pLeft;
                }
            }
            else {
                m_pRoot = pNode->m_pLeft;
            }

            pNode->m_pLeft->m_pParent = pNode->m_pParent;

        }
        else {
            if (pNode->m_pParent != nullptr) {
                //表示只有右儿子
                if (pNode->m_pParent->m_pLeft == pNode) {
                    pNode->m_pParent->m_pLeft = pNode->m_pRight;
                }
                else {
                    pNode->m_pParent->m_pRight = pNode->m_pRight;
                }
            }
            else {
                m_pRoot = pNode->m_pRight;
            }

            pNode->m_pRight->m_pParent = pNode->m_pParent;
        }

        delete pNode;
        m_nSize--;
    }


    return false;
}

CMyTree::CMyTreeNode * CMyTree::Find(int data)
{
    CMyTreeNode* pCur = m_pRoot;

    while (pCur != nullptr){
        
        if (pCur->m_data > data) {
            pCur = pCur->m_pLeft;
        }
        else if (pCur->m_data < data) {
            pCur = pCur->m_pRight;
        }
        else {
            return pCur;
        }
    }

    return nullptr;
}

void CMyTree::Layer(){
    /*
           50
      30       70
    10  40   60   80

    存储：                   输出
    50               
    30  70                  50
    70  10  40              50  30
    10  40  60  80          50  30  70
    40  60  80              50  30  70 10
                            50  30  70 10 40 60 80
   */

    if (m_nSize == 0) {
        return;
    }

  
    std::queue<CMyTreeNode*> que;
    que.push(m_pRoot);

    while (!que.empty()) {
        
        //节点出队列并打印
        CMyTreeNode* pNode = que.front();
        printf("%d ", pNode->m_data);
        que.pop();

        //压入左儿子和右儿子
        if (pNode->m_pLeft != nullptr) {
            que.push(pNode->m_pLeft);
        }

        if (pNode->m_pRight != nullptr) {
            que.push(pNode->m_pRight);
        }
    }
    printf("\r\n");
}

/*
   递归：
   若二叉树为空，则遍历结束；
   否则，执行下列步骤：
        (1) 访问根结点；
        (2) 遍历根的左子树；
        (3) 遍历根的右子树。
*/

void CMyTree::DLR(CMyTreeNode* pNode){

    if (pNode == nullptr) {
        return;
    }

    printf("%d ", pNode->m_data);
    DLR(pNode->m_pLeft);
    DLR(pNode->m_pRight);
}

void CMyTree::_DLR(CMyTreeNode * pNode)
{
    /*
           50
      30       70
    10  40   60   80

    50  30  10   40  70  60  80

    栈： （底-->顶）                输出
    50 
    70  30                         50
    70  40  10                     50 30
    70                             50 30 10 40
    80  60                         50 30 10 40 70
                                   50 30 10 40 70 60 80
   */

    std::stack<CMyTreeNode*> stk;

    if (pNode == nullptr) {
        return;
    }

    stk.push(pNode);

    while (!stk.empty()) {
    
        CMyTreeNode* pCur = stk.top();
        printf("%d ", pCur->m_data);
        stk.pop();

        if (pCur->m_pRight != nullptr) {
            stk.push(pCur->m_pRight);
        }

        if (pCur->m_pLeft != nullptr) {
            stk.push(pCur->m_pLeft);
        }
    }

}

void CMyTree::LDR(CMyTreeNode * pNode)
{
    if (pNode == nullptr) {
        return;
    }

    LDR(pNode->m_pLeft);
    printf("%d ", pNode->m_data);
    LDR(pNode->m_pRight);
}

//非递归中序
    /*
           50
      30       70
    10  40   60   80
       35

    10  30  35  40  50  60  70  80

    栈： （底-->顶）                输出
    50
    50  30
    50  30  10
    50  30                         10
    50                             10  30
    50  40  35                     10  30
    50  40                         10  30  35
    70  60                         10  30  35  40  50
    70                             10  30  35  40  50  60 
    80                             10  30  35  40  50  60  70
                                   10  30  35  40  50  60  70  80
   */
void CMyTree::_LDR(CMyTreeNode * pNode)
{

    std::stack<CMyTreeNode*> stk;

    CMyTreeNode* pLeft = pNode;
    
    while (true) {
       
        while (pLeft!= nullptr) {
            stk.push(pLeft);
            pLeft = pLeft->m_pLeft;
        }
        
        if (stk.empty()) {
            return;
        }

        //表示已经找到最左边
        CMyTreeNode* pCur = stk.top();
        printf("%d ", pCur->m_data);
        stk.pop();

        pLeft = pCur->m_pRight;
    }
}

void CMyTree::LRD(CMyTreeNode * pNode)
{
    if (pNode == nullptr) {
        return;
    }

    LRD(pNode->m_pLeft);
    LRD(pNode->m_pRight);
    printf("%d ", pNode->m_data);
}

//非递归后序
    /*
              50
        30        70
     10    40   60   80

    10  40  30  60  80  70  50
    栈： （底-->顶）                输出
    50  30   10
    50  30                         10
    50  30   40                    10   
    50  30                         10  40
    50                             10  40  30
    50  70  60                     10  40  30
    50  70                         10  40  30  60
    50  70  80                     10  40  30  60
    50  70                         10  40  30  60  80
    50                             10  40  30  60  80  70
                                    10  40  30  60  80  70  50


    */
void CMyTree::_LRD(CMyTreeNode * pNode)
{
    std::stack<CMyTreeNode*> stk;

    CMyTreeNode* pLeft = pNode;
    CMyTreeNode* pPre = nullptr;

    while (true) {

        while (pLeft != nullptr) {
            stk.push(pLeft);
            pLeft = pLeft->m_pLeft;
        }

        if (stk.empty()) {
            return;
        }

        //表示已经找到最左边
        CMyTreeNode* pCur = stk.top();

        if (pCur->m_pRight == nullptr) {
            printf("%d ", pCur->m_data);
            stk.pop();
            pPre = pCur;
        }
        else {
            if (pPre == pCur->m_pRight) {
                printf("%d ", pCur->m_data);
                stk.pop();
                pPre = pCur;
            }
            else {
                pLeft = pCur->m_pRight;
            }
           
        }

    }
}
