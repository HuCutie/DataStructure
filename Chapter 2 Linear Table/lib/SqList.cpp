#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\include\SqList.h"
#include <stdlib.h>

#define random(x) (rand()%x)

bool ListInsert(SqList &L, int i, ElemType e)
{
    if(i < 1 || i > i > L.length + 1)
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

bool ListDelete(SqList &L, int i, ElemType &e)
{
    if(i < 1 || i > L.length + 1)
    {
        return false;
    }
    e = L.data[i-1];
    for(int j = i; j < L.length; j++)
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

int LocateElem(SqList L, ElemType e)
{
    int i ;
    for(i = 0; i < L.length; i++)
    {
        if(L.data[i] == e)
        {
            return i+1;
        }
    }
    return -1;
}

void ListInit(SqList &L, int length)
{
    L.length = length;
    for(int i = 0; i < length; i++)
    {
        L.data[i] = random(50);
    }
}

void ListPrint(SqList L)
{
    if(L.length == 0)
    {
        return ;
    }
    for(int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << "  ";
    }
    cout << endl;
}