// TestIn.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//�ڲ���
template <typename T>
class CMyList {
public:
    template <typename T>
    class CMyItem {

    private:
        T m_nInt;
    };

    CMyItem<T>& GetFirstItem();

private:
    CMyItem<T> m_item[100];
};

template <typename T>
typename CMyList<T>::CMyItem<T>& CMyList<T>::GetFirstItem() {
    return m_item[0];
}

int main()
{
    CMyList<int> lst;

    CMyList<int>::CMyItem<int> it = lst.GetFirstItem();



    return 0;
}

