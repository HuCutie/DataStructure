#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\include\ThreadBiTree.h"

ThreadBiTree CreatThreadBiTreeByPre()
{
    ThreadBiTree T = (ThreadNode *)malloc(sizeof(ThreadNode));
    ElemType t;

    cin >> t;
    if(t == '#')
    {
        return NULL;
    }
    else
    {
        T->data = t;
        T->lchild = CreatThreadBiTreeByPre();
        T->rchild = CreatThreadBiTreeByPre();
    }

    return T;
}

void InThread(ThreadBiTree & T, ThreadNode * & pre)
{
    if(T != NULL)
    {
        InThread(T->lchild, pre);
        if(T->lchild == NULL)
        {
            T->lchild = pre;
            T->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL)
        {
            pre->rchild = T;
            pre->rtag = 1;
        }
        pre = T;
        InThread(T->rchild, pre);
    }
}

void CreateInThread(ThreadBiTree & T)
{
    ThreadNode * pre = NULL;
    if(T != NULL)
    {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

ThreadNode * FirstNode(ThreadBiTree T)
{
    ThreadNode * p = T;
    while(p->ltag == 0)
    {
        p = p->lchild;
    }
    return p;
}

ThreadNode * NextNode(ThreadNode * p)
{
    if(p->rtag == 0)
    {
        return FirstNode(p->rchild);
    }
    else
    {
        return p->rchild;
    }
}

void InOrder(ThreadBiTree T)
{
    for(ThreadNode * p = FirstNode(T); p != NULL; p = NextNode(p))
    {
        cout << p->data << " ";
    }
    cout << endl;
}