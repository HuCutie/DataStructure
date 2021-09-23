#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void SortCLink(LinkList & L)
{
    LNode * p, * pre, * minp, * minpre;
    while(L->next != L)
    {
        pre = L;
        p = L->next;
        minp = p;
        minpre = pre;
        while(p != L)
        {
            if(p->data < minp->data)
            {
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        cout << minp->data << " ";
        minpre->next = minp->next;
        free(minp);
    }
    L = NULL;
    free(L);
    cout << endl;
}

int main()
{
    LinkList L = CLinkInit(5);
    CLinkPrint(L);

    SortCLink(L);
    CLinkPrint(L);
    return 0;
}