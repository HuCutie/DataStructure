#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

LNode * CircleLink(LinkList L)
{
    LNode * fast = L, * slow = L;
    LNode * p, * q;
    while(fast->next != NULL && slow != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
        {
            break;
        }
    }

    if(fast == NULL || slow == NULL)
    {
        return NULL;
    }

    p = L;
    q = slow;
    while(p != q)
    {
        p = p->next;
        q = q->next;
    }

    return p;
}

int main()
{
    LinkList L1 = LinkInit(5);
    LinkPrint(L1);
    LNode * p = L1->next;

    LinkList L2 = CLinkInit(5);

    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = L2->next;

    cout << CircleLink(L1)->data << endl;
    return 0;
}