#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void LinkSplit(LinkList & L, LinkList & L1, LinkList & L2)
{
    LNode * p = L->next;
    LNode * q1 = L1;
    LNode * q2 = L2;
    int count = 1;
    
    while(p != NULL)
    {
        if(count % 2 == 1)
        {
            q1->next = p;
            q1 = q1->next;
            p = p->next;
            q1->next = NULL;
        }
        else
        {
            q2->next = p;
            q2 = q2->next;
            p = p->next;
            q2->next = NULL;
        }
        count++;
    }
    L->next = NULL;
}

int main()
{
    LinkList L = LinkInit(5);
    LinkPrint(L);
    LinkList L1;
    LinkList L2 = LinkInit(0);

    LinkSplit(L, L1, L2);
    LinkPrint(L);
    LinkPrint(L1);
    LinkPrint(L2);
    return 0;
}