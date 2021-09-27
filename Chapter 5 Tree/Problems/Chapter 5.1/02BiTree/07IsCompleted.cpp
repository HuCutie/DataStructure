#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

bool IsCompleted(BiTree T)
{
    BiTNode * p = T;
    SqQueue Q;
    InitQueue(Q);

    if(T == NULL)
    {
        return true;
    }

    if(p != NULL)
    {
        EnQueue(Q, p);
    }

    while(!QueueEmpty(Q))
    {
        DeQueue(Q, p);
        if(p != NULL)
        {
            EnQueue(Q, p->lchild);
            EnQueue(Q, p->rchild);
        }
        else
        {
            while(!QueueEmpty(Q))
            {
                DeQueue(Q, p);
                if(p != NULL)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    BiTree T;
	T = CreatBiTreeByPre();

	PreRec(T);
	cout << endl;

    cout << IsCompleted(T) << endl;
    return 0;
}