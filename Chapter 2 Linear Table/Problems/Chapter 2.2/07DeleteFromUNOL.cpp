#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void DeleteFromUNOL(LinkList & L, ElemType s, ElemType t)
{
    LNode * pre = L, * p = pre->next;
    LNode * q;
    if(s > t)
    {
        cout << "Invalid range." << endl;
        return ;
    }
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
        if(p->data > s && p->data < t)
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

int main()
{
    LinkList L = LinkInit(10);
    LinkPrint(L);

    DeleteFromUNOL(L, 3, 10);
    LinkPrint(L);
    return 0;
}