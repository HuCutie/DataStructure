#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void MergeCLink(LinkList & L1, LinkList & L2)
{
    LNode * l1 = L1->next, * l2 = L2->next;
    while(l1->next != L1)
    {
        l1 = l1->next;
    }
    l1->next = L2->next;
    while(l1->next != L2)
    {
        l1 = l1->next;
    }
    l1->next = L1;
}

int main()
{
    LinkList L1 = CLinkInit(5);
    CLinkPrint(L1);
    LinkList L2 = CLinkInit(5);
    CLinkPrint(L2);
    
    MergeCLink(L1, L2);
    CLinkPrint(L1);
    return 0;
}