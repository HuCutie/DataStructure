#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiSearchTree.cpp"

int GetChildNum(BSTree T)
{
    if(T == NULL)
    {
        return 0;
    }
    else if(T->lchild == NULL && T->rchild == NULL)
    {
        return 0;
    }
    else if(T->lchild != NULL && T->rchild != NULL)
    {
        return GetChildNum(T->lchild) + GetChildNum(T->rchild) + 2;
    }
    else
    {
        return GetChildNum(T->lchild) + GetChildNum(T->rchild) + 1;
    }
}

void Init(BSTree & T)
{
    BSNode * p = T;
    int count;

    if(p != NULL)
    {
        count = GetChildNum(p);
        p->count = count;

        Init(T->lchild);
        Init(T->rchild);
    }
}

BSNode * GetKth(BSTree T, int k)
{
    int count = T->count;

    if(k < 1 || k > count)
    {
        cout << "Invalid range." << endl;
        return NULL;
    }

    if(T->lchild == NULL)
    {
        if(k == 1)
        {
            return T;
        }
        else
        {
            return GetKth(T->rchild, k-1);
        }
    }
    else
    {
        if(T->lchild->count == k-1)
        {
            return T;
        }
        if(T->lchild->count > k-1)
        {
            return GetKth(T->lchild, k);
        }
        else
        {
            return GetKth(T->rchild, k-(T->lchild->count+1));
        }
    }

    return NULL;
}

int main()
{
    BSTree T = Create(5);
    Init(T);
    Print(T);
    cout << endl;

    cout << GetKth(T, 3)->data << endl;

    return 0;
}