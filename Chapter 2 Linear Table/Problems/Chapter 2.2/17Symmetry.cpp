#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

bool Symmetry(CDLinkList CDL)
{
    CDNode * p = CDL->next, * r = CDL->prior;
    while(p != r)
    {
        if(p->data == r->data)
        {
            p = p->next;
            r = r->prior;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    CDLinkList L = CDLinkInit(5);
    cout << Symmetry(L) << endl;
    return 0;
}