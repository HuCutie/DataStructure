#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

bool SubSequence(LinkList L1, LinkList L2)
{
    LNode * l1 = L1->next, * l2 = L2->next;
    LNode * p, * q;
    while(l1 != NULL)
    {
        p = l1;
        l2 = L2->next;
        while(l2 != NULL)
        {
            if(p->data == l2->data)
            {
                p = p->next;
                l2 = l2->next;
            }
            else
            {
                break;
            }
        }
        if(l2 == NULL)
        {
            return true;
        }
        l1 = l1->next;
    }

    return false;
}

int main()
{
    LinkList L1 = LinkInit(5);
    LinkPrint(L1);
    LinkList L2= LinkInit(3);
    LinkPrint(L2);

    cout << SubSequence(L1, L2) << endl;
    return 0;
}