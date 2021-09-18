#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\include\LinkList.h"

LinkList LinkInit(int n)
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    LNode * s;
    int i = 0;
    L->next = NULL;
    while(i < n)
    {
        s = (LNode *)malloc(sizeof(LNode));
        cin >> s->data;
        s->next = L->next;
        L->next = s;
        i++;
    }
    return L;
}

void LinkPrint(LinkList L)
{
    while(L->next != NULL)
    {
        cout << L->next->data << " ";
        L = L->next;
    }
    cout << endl;
}

LinkList LinkHInsert(int n)
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    LNode * s;
    int i = 0;
    L->next = NULL;
    while(i < n)
    {
        s = (LNode *)malloc(sizeof(LNode));
        cin >> s->data;
        s->next = L->next;
        L->next = s;
        i++;
    }
    return L;
}

LinkList LinkTInsert(int n)
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    LNode * s, * r;
    int i = 0;
    L->next = NULL;
    r = L;
    while(i < n)
    {
        s = (LNode *)malloc(sizeof(LNode));
        cin >> s->data;
        r->next = s;
        s->next = NULL;
        r = s;
        i++;
    }
    return L;
}

LNode * GetElemByNum(LinkList L, int num)
{
    int i = 1;
    LNode * p = L->next;
    if(num == 0)
    {
        return L;
    }
    if(num < 0)
    {
        return NULL;
    }
    while(i < num && p != NULL)
    {
        p = p->next;
        i++;
    }
    return p;
}

LNode * GetElemByVal(LinkList L, ElemType e)
{
    LNode * p = L->next;
    while(p != NULL)
    {
        if(p->data == e)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

LNode * LinkInsert(LinkList & L, int num, ElemType e)
{
    LNode * p = (LNode *)malloc(sizeof(LNode));
    p->data = e;
    LNode * pre = GetElemByNum(L, num-1);

    p->next = pre->next;
    pre->next = p;

    return p;
}

void LinkDelete(LinkList & L, int num)
{
    LNode * pre = GetElemByNum(L, num-1);
    LNode * p = pre->next;

    pre->next = p->next;
    free(p);
}

int GetLinkLength(LinkList L)
{
    int length = 0;
    LNode * p = L->next;
    if(L == NULL)
    {
        return -1;
    }
    if(L->next == NULL)
    {
        return 0;
    }
    while(p != NULL)
    {
        p = p->next;
        length++;
    }
    return length;
}