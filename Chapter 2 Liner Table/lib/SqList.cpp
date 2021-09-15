#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Liner Table\include\SqList.h"

bool ListInsert(SqList &L, int i, ElemType e)
{
    if(i < 1 || i > i>L.length + 1)
    {
        return false;
    }
    if(L.length >= MaxSize)
    {
        return false;
    }
    for(int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}