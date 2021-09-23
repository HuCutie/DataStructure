#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

LinkList CommonNode2(LinkList & L1, LinkList & L2)
{
    LinkList L;
    LNode * p = L;
    LNode * l1 = L1->next, * l2 = L2->next;
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->data > l2->data)
        {
            l2 = l2->next;
        }
        else if(l1->data < l2->data)
        {
            l1 = l1->next;
        }
        else
        {
            LNode * s = (LNode *)malloc(sizeof(LNode));
            s->data = l1->data;
            p->next = s;
            p = p->next;
            p->next = NULL;

            l1 = l1->next;
            l2 = l2->next;
        }
    }

    return L;
}

int main()
{
    LinkList L1 = LinkInit(5);
    LinkPrint(L1);
    LinkList L2= LinkInit(5);
    LinkPrint(L2);

    LinkList L = CommonNode2(L1, L2);
    
    LinkPrint(L);
    return 0;
}