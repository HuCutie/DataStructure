#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\include\BiTree.h"

void InitStack(SqStack & S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    if(S.top == -1)
    {
        return true;
    }
    return false;
}

bool Push(SqStack & S, BiTNode * p)
{
    if(S.top == MaxSize - 1)
    {
        cout << "Stack is full." << endl;
        return false;
    }
    S.data[++S.top] = p;
    return true;
}

bool Pop(SqStack & S, BiTNode * & p)
{
    if(S.top == -1)
    {
        cout << "Stack is full." << endl;
        return false;
    }
    p = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, BiTNode * & p)
{
    if(S.top == -1)
    {
        cout << "Stack is full." << endl;
        return false;
    }
    p = S.data[S.top];
    return true;
}

void InitQueue(SqQueue & Q)
{
    Q.front = 0;
    Q.rear = 0;
}

bool QueueEmpty(SqQueue Q)
{
    if(Q.rear == Q.front)
    {
        return true;
    }
    return false;
}

bool EnQueue(SqQueue & Q, BiTNode * p)
{
    if((Q.rear + 1) % MaxSize == Q.front)
    {
        cout << "Queue is full." << endl;
        return false;
    }
    Q.data[Q.rear] = p;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue & Q, BiTNode * & p)
{
    if(Q.rear == Q.front)
    {
        cout << "Queue is empty." << endl;
        return false;
    }
    p = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

BiTree CreatBiTreeByPre()
{
    BiTree T = (BiTNode *)malloc(sizeof(BiTNode));
    ElemType t;

    cin >> t;
    if(t == '#')
    {
        return NULL;
    }
    else
    {
        T->data = t;
        T->lchild = CreatBiTreeByPre();
        T->rchild = CreatBiTreeByPre();
    }

    return T;
}

void PreRec(BiTree T)
{
    if(T != NULL)
    {
        cout << T->data << " ";
        PreRec(T->lchild);
        PreRec(T->rchild);
    }
}

void MidRec(BiTree T)
{
    if(T != NULL)
    {
        MidRec(T->lchild);
        cout << T->data << " ";
        MidRec(T->rchild);
    }
}

void PosRec(BiTree T)
{
    if(T != NULL)
    {
        PosRec(T->lchild);
        PosRec(T->rchild);
        cout << T->data << " ";
    }
}

void Pre(BiTree T, SqStack S)
{
    InitStack(S);
    BiTNode * p = T;

    while(p != NULL || !StackEmpty(S))
    {
        if(p != NULL)
        {
            cout << p->data << " ";
            Push(S, p);
            p = p->lchild;
        }
        else
        {
            Pop(S, p);
            p = p->rchild;
        }
    }
}

void Mid(BiTree T, SqStack S)
{
    InitStack(S);
    BiTNode * p = T;

    while(p != NULL || !StackEmpty(S))
    {
        if(p != NULL)
        {
            Push(S, p);
            p = p->lchild;
        }
        else
        {
            Pop(S, p);
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

void Pos(BiTree T, SqStack S)
{
    InitStack(S);
    BiTNode * p = T;
    BiTNode * r = NULL;

    while(p != NULL || !StackEmpty(S))
    {
        if(p != NULL)
        {
            Push(S, p);
            p = p->lchild;
        }
        else
        {
            GetTop(S, p);
            if(p->rchild != NULL && p->rchild != r)
            {
                p = p->rchild;
            }
            else
            {
                Pop(S, p);
                cout << p->data << " ";
                r = p;
                p = NULL;
            }
        }
    }
}

void Hir(BiTree T, SqQueue Q)
{
    InitQueue(Q);
    BiTNode * p = T;

    if(p != NULL)
    {
        EnQueue(Q, p);
    }

    while(!QueueEmpty(Q))
    {
        DeQueue(Q, p);
        cout << p->data << " ";
        if(p->lchild != NULL)
        {
            EnQueue(Q, p->lchild);
        }
        if(p->rchild != NULL)
        {
            EnQueue(Q, p->rchild);
        }
    }
}