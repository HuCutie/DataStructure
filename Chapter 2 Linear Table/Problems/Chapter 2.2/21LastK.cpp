#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

bool LastK(LinkList L, int k)
{
    LNode * l = L->next, * p = L->next;
    int length = GetLinkLength(L);
    if(k > length)
    {
        return false;
    }

    for(int i = 0; i < k; i++)
    {
        l = l->next;
    }

    while(l != NULL)
    {
        l = l->next;
        p = p->next;
    }

    cout << p->data << endl;
    return true;
}

int main()
{
    LinkList L = LinkInit(10);
    LinkPrint(L);
    
    cout << LastK(L, 1) << endl;
    cout << LastK(L, 5) << endl;
    cout << LastK(L, 10) << endl;
    cout << LastK(L, 11) << endl;
    return 0;
}