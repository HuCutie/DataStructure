#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void DeleteAbs(LinkList & L)
{
    LNode * pre = L;
    LNode * p = pre->next;
    LNode * q;
    int len = GetLinkLength(L);
    int * a = (int *)malloc(sizeof(int) * len + 1);

    for(int i = 0; i < len + 1; i++)
    {
        a[i] = 0;
    }

    while(p != NULL)
    {
        if(a[abs(p->data)] == 1)
        {
            q = p;
            pre->next = p->next;
            p = p->next;
            free(q);
        }
        else
        {
            a[abs(p->data)] = 1;
            pre = p;
            p = p->next;
        }
    }
}

int main()
{
    LinkList L = LinkInit(10);
    LinkPrint(L);
    
    DeleteAbs(L);
    LinkPrint(L);
    return 0;
}