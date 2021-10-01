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

BSNode * Parent(BSTree T, BSNode * p)
{
    if(T->lchild == p || T->rchild == p)
    {
        return T;
    }
    else if(T->data < p->data)
    {
        return Parent(T->rchild, p);
    }
    else if(T->data > p->data)
    {
        return Parent(T->lchild, p);
    }
    return NULL;
}

bool Delete(BSTree & T, ElemType x)
{
    BSNode * p = Search(T, x);
    BSNode * q, * r;
    if(p == NULL)
    {
        cout << "The node is not in the tree." << endl;
        return false;
    }

    if(p->lchild == NULL && p->rchild == NULL)
    {
        q = Parent(T, p);
        if(q->lchild == p)
        {
            q->lchild = NULL;
        }
        if(q->rchild == p)
        {
            q->rchild = NULL;
        }
    }
    else if((p->lchild != NULL && p->rchild == NULL) || (p->lchild == NULL && p->rchild != NULL))
    {
        q = Parent(T, p);
        r = p->lchild != NULL ? p->lchild : p->rchild;
        if(p->data < q->data)
        {
            q->lchild = r;
        }
        if(p->data > q->data)
        {
            q->rchild = r;
        }
    }
    else
    {
        q = Parent(T, p);
        r = p->lchild;

        if(r->rchild == NULL)
        {
            q->lchild = r;
            r->rchild = p->rchild;
        }
        else
        {
            BSNode * r1 = r;
            BSNode * r1Parent = r;
            while(r1->rchild != NULL)
            {
                r1Parent = r1;
                r1 = r1->rchild;
            }

            r1Parent->rchild = r1->lchild;
            r1->lchild = r;
            r1->rchild = p->rchild;

            if(q->lchild == p)
            {
                q->lchild = r1;
            }
            if(q->rchild == p)
            {
                q->rchild = r1;
            }
        }
    }

    free(p);
    return true;
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
        Print(p->lchild);
        cout << p->data << " ";
        Print(p->rchild);
    }
}