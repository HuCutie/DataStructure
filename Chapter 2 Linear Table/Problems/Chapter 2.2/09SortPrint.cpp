#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void SortPrint(LinkList & L)
{
    LNode * p, * q, * r;
    p = L->next;
    while(p != NULL)
    {
        q = L->next;
        while(q->next != NULL)
        {
            r = q->next;
            if(q->data > r->data)
            {
                ElemType t = q->data;
                q->data = r->data;
                r->data = t;
            }
            q = q->next;
        }
        p = p->next;
    }

    p = L->next;
    while(p != NULL)
    {
        cout << p->data << " ";
        q = p;
        p = p->next;
        free(q);
    }
    cout << endl;
    L->next = NULL;
}

int main()
{
    LinkList L = LinkInit(5);
    LinkPrint(L);

    SortPrint(L);
    LinkPrint(L);
    return 0;
}