#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\include\BiSearchTree.h"

BSNode * Search(BSTree T, ElemType x)
{
    BSNode * p = T;
    while(p != NULL && p->data != x)
    {
        if(x < p->data)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }

    if(p->data == x)
    {
        return p;
    }
    return NULL;
}

void Insert(BSTree & T, ElemType x)
{
    if(T == NULL)
    {
        T = (BSNode *)malloc(sizeof(BSNode));
        T->data = x;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    else if(T->data == x)
    {
        cout << "There is already a node in the tree." << endl;
        return ;
    }
    else if(x < T->data)
    {
        return Insert(T->lchild, x);
    }
    else
    {
        return Insert(T->rchild, x);
    }
}

void Delete(BSTree & T, ElemType x)
{
    BSNode * p = Search(T, x);
    if(p == NULL)
    {
        cout << "The node is not in the tree." << endl;
        return ;
    }

    if(p->lchild == NULL && p->rchild == NULL)
    {
        ;
    }
}

BSTree Create(int n)
{
    BSTree T = NULL;
    int i = 0;
    ElemType data;

    while(i < n)
    {
        cin >> data;
        Insert(T, data);
        i++;
    }

    return T;
}

void Print(BSTree T)
{
    BSNode * p = T;
    if(p != NULL)
    {
        cout << p->data << " ";
        Print(p->lchild);
        Print(p->rchild);
    }
}

int main()
{
    BSNode * p;
    BSTree T = Create(6);
    Print(T);
    cout << endl;
    p = Search(T, 5);
    cout << p << "  " << p->data << endl;

    Insert(T, 10);
    Print(T);
    cout << endl;

    Insert(T, 0);
    Print(T);
    cout << endl;

    return 0;
}