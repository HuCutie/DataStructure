#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\include\Forest.h"

CSTree Create()
{
    CSTree T = (CSNode *)malloc(sizeof(CSNode));
    CSNode * p = T;
    ElemType t;

    cin >> t;
    if(t == '#')
    {
        return NULL;
    }
    else
    {
        T->data = t;
        T->firstChild = Create();
        T->nextSibling = Create();
    }

    return T;
}

void Pre(CSTree T)
{
    if(T != NULL)
    {
        cout << T->data << " ";
        Pre(T->firstChild);
        Pre(T->nextSibling);
    }
}