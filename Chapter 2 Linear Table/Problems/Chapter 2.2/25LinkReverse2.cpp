#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void LinkReverse2(LinkList & L)
{
    LNode * p = L;
    LNode * q, * r, * mid;
    int len = GetLinkLength(L);
    if(len % 2 == 1)
    {
        len++;
    }

    for(int i = 0; i < len / 2; i++)
    {
        p = p->next;
    }
    mid = p;

    q = p->next;
    p->next = NULL;
    while(q != NULL)
    {
        r = q;
        q = q->next;
        r->next = p->next;
        p->next = r;
    }

    p = L->next;
    q = mid->next;
    mid->next = NULL;
    while(q != NULL)
    {
        r = q->next;
        q->next = p->next;
        p->next = q;
        p = p->next->next;
        q = r;
    }
}

int main()
{
    LinkList L = LinkInit(5);
    LinkPrint(L);
    
    LinkReverse2(L);
    LinkPrint(L);
    return 0;
}