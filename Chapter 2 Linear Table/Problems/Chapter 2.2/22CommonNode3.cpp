#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

LNode * CommonNode3(LinkList L1, LinkList L2)
{
    LNode * l1 = L1->next, * l2 = L2->next;
    int len1 = GetLinkLength(L1);
    int len2 = GetLinkLength(L2);
    int dist = len1-len2;

    if(dist < 0)
    {
        dist = -dist;
        for(int i = 0; i < dist; i++)
        {
            l2 = l2->next;
        }
    }
    else
    {
        for(int i = 0; i < dist; i++)
        {
            l1 = l1->next;
        }
    }

    while(l1 != l2 && l1 != NULL && l2 != NULL)
    {
        l1 = l1->next;
        l2 = l2->next;
    }

    if(l1 == NULL && l2 == NULL)
    {
        return NULL;
    }

    return l1;
}

int main()
{
    LinkList L1 = LinkInit(1);
    LinkList L2 = LinkInit(3);
    LNode * t1 = L1, * t2 = L2;
    LNode * q;

    while(t1->next != NULL)
    {
        t1 = t1->next;
    }
    while(t2->next != NULL)
    {
        t2 = t2->next;
    }

    for(int i = 0; i < 3; i++)
    {
        ElemType data;
        cin >> data;
        LNode * p = (LNode *)malloc(sizeof(LNode));
        p->data = data;
        p->next = NULL;
        if(p->data == 6)
        {
            cout << "p->data: " << p->data << "  p:" << p << endl;
        }
        t1->next = p;
        t2->next = p;
        t1 = t1->next;
        t2 = t2->next;
    }

    q = CommonNode3(L1, L2);
    cout << "q->data: " << q->data << "  q:" << q << endl;
    return 0;
}