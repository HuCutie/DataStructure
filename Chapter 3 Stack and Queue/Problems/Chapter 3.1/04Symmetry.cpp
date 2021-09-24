#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 3 Stack and Queue\lib\Stack.cpp"
#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

bool Symmetry(LinkList L, SqStack & S)
{
    LNode * p = L->next;
    int len = GetLinkLength(L);
    bool flag = false;
    ElemType x;

    if(len % 2 == 1)
    {
        len--;
        flag = true;
    }
    for(int i = 0; i < len / 2; i++)
    {
        Push(S, p->data);
        p = p->next;
    }

    if(flag)
    {
        p = p->next;
    }
    while(p != NULL)
    {
        GetTop(S, x);
        if(p->data != x)
        {
            return false;
        }
        else
        {
            p = p->next;
            Pop(S, x);
        }
    }

    if(S.top == -1)
    {
        return true;
    }
    return false;
}

int main()
{
    SqStack S;
    InitStack(S);

    LinkList L = LinkInit(6);

    cout << Symmetry(L, S) << endl;
    return 0;
}