#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void LinkSort(LinkList & L)
{
    ElemType tmp;
    LNode * p = L->next;
    LNode * pre;
    LNode * q;
    
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
        pre = L->next;
        q = pre->next;
        while(q != NULL)
        {
            if(pre->data > q->data)
            {
                tmp = pre->data;
                pre->data = q->data;
                q->data = tmp;
            }
            pre = q;
            q = q->next;
        }
        p = p->next;
    }
}

int main()
{
    LinkList L = LinkInit(5);
    LinkPrint(L);

    LinkSort(L);
    LinkPrint(L);
    return 0;
}