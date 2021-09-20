#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void DeleteXByRec(LinkList & L, ElemType x)
{
    LNode * p;
    if(L == NULL)
    {
        return ;
    }
    if(L->data == x)
    {
        p = L;
        L = L->next;

        free(p);
        DeleteXByRec(L, x);
    }
    else
    {
        DeleteXByRec(L->next, x);
    }
}

int main()
{
    LinkList L = LinkInit(5);
    LinkPrint(L);

    DeleteXByRec(L->next, 3);
    LinkPrint(L);
    return 0;
}