#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void DeleteReplicate(LinkList & L)
{
    if(L == NULL)
    {
        return ;
    }
    if(L->next == NULL)
    {
        cout << "Empty list." << endl;
        return ;
    }

    LNode * p = L->next, * q;
    while(p->next != NULL)
    {
        q = p->next;
        if(p->data == q->data)
        {
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

    DeleteReplicate(L);
    LinkPrint(L);
    return 0;
}