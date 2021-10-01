#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\include\BiBalancedTree.h"

void Print(BBTree T)
{
    if(T != NULL)
    {
        Print(T->lchild);
        cout << T->data << " ";
        Print(T->rchild);
    }
}

BBNode * LL(BBNode * p)
{
    BBNode * l = p->lchild;
    
    p->lchild = l->rchild;
    l->rchild = p;

    return l;
}

BBNode * RR(BBNode * p)
{
    BBNode * r = p->rchild;

    p->rchild = r->lchild;
    r->lchild = p;

    return r;
}

BBNode * LR(BBNode * p)
{
    p->lchild = (p->lchild);
    return LL(p);
}

BBNode * RL(BBNode * p)
{
    p->rchild = (p->rchild);
    return RR(p);
}

BBNode * Search(BBTree T, ElemType x)
{
    BBNode * p = T;

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

    if(p != NULL && p->data == x)
    {
        return p;
    }
    return NULL;
}

BBNode * Parent(BBTree T, BBNode * p)
{
    if(T->lchild == p || T->rchild == p)
    {
        return T;
    }
    else if(p->data < T->data)
    {
        return Parent(T->lchild, p);
    }
    else if(p->data > T->data)
    {
        return Parent(T->rchild, p);
    }

    return NULL;
}

int getHeight(BBNode * p)
{
    if(p == NULL)
    {
        return 0;
    }
    int l = getHeight(p->lchild);
    int r = getHeight(p->rchild);
    return l > r ? l+1 : r+1;
}

int getDiffer(BBNode * p)
{
    if(p == NULL)
    {
        return 0;
    }

    return getHeight(p->lchild) - getHeight(p->rchild);
}

BBTree Balance(BBNode * & p)
{
    int diff = getDiffer(p);

    if(diff > 1)
    {
        if(getDiffer(p->lchild) > 0)
        {
            p = LL(p);
        }
        else
        {
            p = LR(p);
        }
    }
    else if(diff < -1)
    {
        if(getDiffer(p->rchild) < 0)
        {
            p = RR(p);
        }
        else
        {
            p = RL(p);
        }
    }

    return p;
}

void Insert(BBTree & T, ElemType x)
{
    if(T == NULL)
    {
        T = (BBNode *)malloc(sizeof(BBNode));
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
        Insert(T->lchild, x);
        T = Balance(T);
    }
    else
    {
        Insert(T->rchild, x);
        T = Balance(T);
    }
}

BBTree Create(int n)
{
    BBTree T = NULL;
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

bool Delete(BBTree & T, ElemType x)
{
    BBNode * p = Search(T, x);
    BBNode * q, * r;
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
    else if((p->lchild == NULL && p->rchild != NULL) || (p->lchild != NULL && p->rchild == NULL))
    {
        q = Parent(T, p);
        r = p->lchild == NULL ? p->rchild : p->lchild;

        if(q->lchild == p)
        {
            q->lchild = r;
        }
        if(q->rchild == p)
        {
            q->rchild = r;
        }
    }
    else
    {
        BBNode *r1 = r;
        BBNode *r1Parent = r;
        while (r1->rchild != NULL)
        {
            r1Parent = r1;
            r1 = r1->rchild;
        }

        r1Parent->rchild = r1->lchild;
        r1->lchild = r;
        r1->rchild = p->rchild;

        if (q->lchild == p)
        {
            q->lchild = r1;
        }
        if (q->rchild == p)
        {
            q->rchild = r1;
        }
    }

    T = Balance(T);
    free(p);
    return true;
}

int main()
{
    BBTree T = Create(6);
    BBNode * p;

    Print(T);
    cout << endl;

    Insert(T, 0);
    Print(T);
    cout << endl;

    Insert(T, 10);
    Print(T);
    cout << endl;

    Delete(T, 0);
    Print(T);
    cout << endl;

    Delete(T, 10);
    Print(T);
    cout << endl;

    return 0;
}