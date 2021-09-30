#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

void ReversePrint(LinkList L)
{
    if(L->next->next != NULL)
    {
        ReversePrint(L->next);
    }
    cout << L->next->data << " ";
}

int main()
{
    LinkList L = LinkInit(10);
    LinkPrint(L);

    ReversePrint(L);
    return 0;
}