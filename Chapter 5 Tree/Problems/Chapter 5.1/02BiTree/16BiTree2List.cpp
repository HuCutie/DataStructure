#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

void BiTree2List(BiTree & T, SqQueue Q, SqQueue Q1)
{
    BiTNode * p = T;
    BiTNode * q;
    if(T == NULL)
    {
        return ;
    }

    InitQueue(Q);
    InitQueue(Q1);

    EnQueue(Q, p);
    while(!QueueEmpty(Q))
    {
        DeQueue(Q, p);
        EnQueue(Q1, p);

        if(p->lchild != NULL)
        {
            EnQueue(Q, p->lchild);
        }
        if(p->rchild != NULL)
        {
            EnQueue(Q, p->rchild);
        }
    }

    DeQueue(Q1, p);
    p->rchild = NULL;
    while(!QueueEmpty(Q1))
    {
        DeQueue(Q1, q);
        q->rchild = p->rchild;
        p->rchild = q;
        p = p->rchild;
    }
}

int main()
{
    BiTree T;
    BiTNode * p = T;
	T = CreatBiTreeByPre();
	SqQueue Q;
    SqQueue Q1;

	Hir(T, Q);
	cout << endl;

    BiTree2List(T, Q, Q1);

    while(T != NULL)
    {
        cout << T->data << " ";
        T = T->rchild;
    }
    cout << endl;

    return 0;
}