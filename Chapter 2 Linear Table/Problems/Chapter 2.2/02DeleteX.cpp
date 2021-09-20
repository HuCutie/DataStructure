#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void DeleteX(LinkList & L, ElemType x)
{
    LNode * p = L, * q;
    if(L == NULL)
    {
        return ;
    }
    if(L->next == NULL)
    {
        cout << "Empty list." << endl;
        return ;
    }
    while(p->next != NULL)
    {
        if(p->next->data == x)
        {
            q = p->next;
            p->next = q->next;
            free(q);
        }
        else
        {
            p = p->next;
        }
    }
}

int main()
{
    LinkList L = LinkInit(10);
    LinkPrint(L);

    DeleteX(L, 3);
    LinkPrint(L);
    return 0;
}