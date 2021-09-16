#ifndef SQLIST_H_
#define SQLIST_H_

#include <iostream>

using namespace std;

#define MaxSize 50

#define ElemType int

struct SqList
{
    ElemType data[MaxSize];
    int length;
};

bool ListInsert(SqList &L, int i, ElemType e);
bool ListDelete(SqList &L, int i, ElemType &e);
int  LocateElem(SqList L, ElemType e);
void ListInit(SqList &L, int length);
void ListPrint(SqList L);

#endif