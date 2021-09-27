#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

void Level(BiTree T, SqQueue Q)
{
    InitQueue(Q);
    BiTNode * p = T;
    EnQueue(Q, p);

    while(p != NULL && !QueueEmpty(Q))
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

int main()
{
    BiTree T;
	T = CreatBiTreeByPre();
	SqQueue Q;

	Hir(T, Q);
	cout << endl;
    Level(T, Q);
    cout << endl;

    return 0;
}