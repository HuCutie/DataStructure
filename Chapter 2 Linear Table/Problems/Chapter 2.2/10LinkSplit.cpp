#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void LinkSplit(LinkList & A, LinkList & B)
{
    B->next = NULL;
    int count = 1;
    LNode * pre = A;
    LNode * p = pre->next;
    LNode * q = B;
    while(p != NULL)
    {
        if(count % 2 == 0)
        {
            pre->next = p->next;
            q->next = p;
            q = q->next;
        }
        pre = p;
        p = p->next;
        count++;
    }
}

int main()
{
    LinkList L = LinkInit(10);
    LinkPrint(L);
    LinkList L1;

    LinkSplit(L, L1);
    LinkPrint(L);
    LinkPrint(L1);
    return 0;
}