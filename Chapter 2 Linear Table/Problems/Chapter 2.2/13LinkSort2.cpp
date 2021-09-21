#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

LinkList LinkSort2(LinkList & L1, LinkList & L2)
{
    LNode * L = (LNode *)malloc(sizeof(LNode));
    LNode * p, * q;
    LNode * l1 = L1->next, * l2 = L2->next;

    while(l1 != NULL && l2 != NULL)
    {
        p = L;
        if(l1->data > l2->data)
        {
            q = l1;
            l1 = l1->next;
            q->next = p->next;
        }
        else
        {

        }
    }

    return L;
}

int main()
{
    LinkList L1 = LinkInit(5);
    LinkPrint(L1);
    LinkList L2 = LinkInit(5);
    LinkPrint(L2);

    LinkList L = LinkSort2(L1, L2);
    LinkPrint(L);

    return 0;
}