#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void Intersection(LinkList & L1, LinkList & L2)
{
    LNode * l1 = L1->next, * l2 = L2->next;
    LNode * p = L1;

    while(l1 != NULL && l2 != NULL)
    {
        if(l1->data < l2->data)
        {
            l1 = l1->next;
        }
        else if(l1->data < l2->data)
        {
            l2 = l2->next;
        }
        else
        {
            p->next = l1;
            l1 = l1->next;
            l2 = l2->next;
            p = p->next;
            p->next = NULL;
        }
    }
}

int main()
{
    LinkList L1 = LinkInit(5);
    LinkPrint(L1);
    LinkList L2= LinkInit(5);
    LinkPrint(L2);

    Intersection(L1, L2);
    
    LinkPrint(L1);
    return 0;
}