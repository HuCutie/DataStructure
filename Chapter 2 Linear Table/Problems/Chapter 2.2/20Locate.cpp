#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

DNode * Locate(DLinkList & DL, ElemType x)
{
    DNode * l = DL->next;
    DNode * p = NULL;
    while(l != NULL)
    {
        if(l->data == x)
        {
            p = l;
            (l->freq)++;
            break;
        }
        l = l->next;
    }

    if(p == NULL)
    {
        return NULL;
    }

    p = l->prior;
    while(p != DL && p->freq <= l->freq)
    {
        p = p->prior;
    }

    if(l->next == NULL)
    {
        l->prior->next = NULL;
    }
    else
    {
        l->prior->next = l->next;
        l->next->prior = l->prior;
    }

    l->next = p->next;
    p->next->prior = l;
    p->next = l;
    l->prior = p;

    return l;
}

int main()
{
    DLinkList DL = DLinkInit(5);
    DNode * p;
    DLinkPrint(DL);
    ElemType x;

    cin >> x;
    p = Locate(DL, x);
    cout << p->data << "  " << p->freq << endl;
    DLinkPrint(DL);

    cin >> x;
    p = Locate(DL, x);
    cout << p->data << "  " << p->freq << endl;
    DLinkPrint(DL);

    cin >> x;
    p = Locate(DL, x);
    cout << p->data << "  " << p->freq << endl;
    DLinkPrint(DL);

    cin >> x;
    p = Locate(DL, x);
    cout << p->data << "  " << p->freq << endl;
    DLinkPrint(DL);

    cin >> x;
    p = Locate(DL, x);
    cout << p->data << "  " << p->freq << endl;
    DLinkPrint(DL);
    return 0;
}