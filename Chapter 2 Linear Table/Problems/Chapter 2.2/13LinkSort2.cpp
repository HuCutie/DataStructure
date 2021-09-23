#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void LinkSort2(LinkList & L1, LinkList & L2)
{
    LNode * l1 = L1->next, * l2 = L2->next;
    LNode * r;

    L1->next = NULL;
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->data < l2->data)
        {
            r = l1->next;
            l1->next = L1->next;
            L1->next = l1;
            l1 = r;
        }
        else
        {
            r = l2->next;
            l2->next = L1->next;
            L1->next = l2;
            l2 = r;
        }
    }

    if(l1 != NULL)
    {
        l2 = l1;
    }
    while(l2 != NULL)
    {
        r = l2->next;
        l2->next = L1->next;
        L1->next = l2;
        l2 = r;
    }

    free(L2);
}

int main()
{
    LinkList L1 = LinkInit(5);
    LinkPrint(L1);
    LinkList L2 = LinkInit(5);
    LinkPrint(L2);

    LinkSort2(L1, L2);
    LinkPrint(L1);

    return 0;
}