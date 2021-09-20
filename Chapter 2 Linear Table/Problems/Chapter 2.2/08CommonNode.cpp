#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

LNode * CommonNode(LinkList L1, LinkList L2)
{
    int l1 = GetLinkLength(L1);
    int l2 = GetLinkLength(L2);
    int dist;
    LNode * longList, * shortList;

    if(l1 > l2)
    {
        longList = L1;
        shortList = L2;
        dist = l1 - l2;
    }
    else
    {
        longList = L2;
        shortList = L1;
        dist = l2 -l1;
    }

    while(dist--)
    {
        longList = longList->next;
    }

    while(longList != NULL)
    {
        if(longList == shortList)
        {
            return longList;
        }
        else
        {
            longList = longList->next;
            shortList = shortList->next;
        }
    }

    return NULL;
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

    q = CommonNode(L1, L2);
    cout << "q->data: " << q->data << "  q:" << q << endl;

    return 0;
}