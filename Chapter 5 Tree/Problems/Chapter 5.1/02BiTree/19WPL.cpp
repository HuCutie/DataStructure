#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

int WPLR(BiTree T, int depth)
{
    int static wpl = 0;
    if(T->lchild == NULL && T->rchild == NULL)
    {
        wpl += depth * (T->data - '0');
    }

    if(T->lchild != NULL)
    {
        WPLR(T->lchild, depth + 1);
    }

    if(T->rchild != NULL)
    {
        WPLR(T->rchild, depth + 1);
    }

    return wpl;
}

int WPLQ(BiTree T, SqQueue Q)
{
    int wpl = 0;
    int depth = 0;
    BiTNode * p = T;
    BiTNode * currentLast = p;
    BiTNode * nextLast = NULL;

    InitQueue(Q);

    if(p == NULL)
    {
        return 0;
    }

    EnQueue(Q, p);
    while(!QueueEmpty(Q))
    {
        DeQueue(Q, p);
        if(p->lchild == NULL && p->rchild == NULL)
        {
            wpl += depth * (p->data - '0');
        }

        if(p->lchild != NULL)
        {
            EnQueue(Q, p->lchild);
            nextLast = p->lchild;
        }
        if(p->rchild != NULL)
        {
            EnQueue(Q, p->rchild);
            nextLast = p->rchild;
        }

        if(p == currentLast)
        {
            currentLast = nextLast;
            depth++;
        }
    }

    return wpl;
}

int main()
{
    BiTree T;
	T = CreatBiTreeByPre();
    SqQueue Q;

	PreRec(T);
	cout << endl;

    cout << WPLR(T, 0) << endl;
    cout << WPLQ(T, Q) << endl;

    return 0;
}