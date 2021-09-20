#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void LinkReverse(LinkList & L)
{
    LNode * pre;
    LNode * p = L->next;
    LNode * r = p->next;
    LNode * first = L->next;    

    first->next = NULL;

    if (L == NULL)
    {
        return;
    }
    if (L->next == NULL)
    {
        cout << "Empty list." << endl;
        return;
    }

    while(r != NULL)
    {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }

    L->next = p;    
}

int main()
{
    LinkList L = LinkInit(5);
    LinkPrint(L);

    LinkReverse(L);
    LinkPrint(L);
    return 0;
}