#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void DeleteMin(LinkList & L)
{
    LNode * p = L->next, * q = L->next, * r = L;
    int min = p->data;
    
    if(L == NULL)
    {
        return ;
    }
    if(L->next == NULL)
    {
        cout << "Empty list." << endl;
        return ;
    }

    while(p != NULL)
    {
        if(p->data < min)
        {
            min = p->data;            
        }
        p = p->next;
    }

    while(q != NULL)
    {
        if(q->data == min)
        {
            r->next = q->next;
            free(q);
            break;
        }
        r = q;
        q = q->next;
    }
}

int main()
{
    LinkList L = LinkInit(10);
    LinkPrint(L);

    DeleteMin(L);
    LinkPrint(L);
    return 0;
}