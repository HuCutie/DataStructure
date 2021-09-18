#include <iostream>

using namespace std;

#define ElemType int

typedef struct LNode
{
    ElemType data;
    struct LNode * next;
}LNode, *LinkList;

LinkList LinkInit(int n);
void LinkPrint(LinkList L);
LinkList LinkHInsert(int n);
LinkList LinkTInsert(int n);
LNode * GetElemByNum(LinkList L, int num);
LNode * GetElemByVal(LinkList L, ElemType e);
LNode * LinkInsert(LinkList & L, int num, ElemType e);
void LinkDelete(LinkList & L, int num);
int GetLinkLength(LinkList L);