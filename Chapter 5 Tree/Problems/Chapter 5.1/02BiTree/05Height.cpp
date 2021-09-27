#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

int Height(BiTree T)
{
    int height = 0;
    BiTNode * p = T;
    if(T == NULL)
    {
        return 0;
    }

    SqQueue Q;
    InitQueue(Q);
    EnQueue(Q, p);
    
    while(!QueueEmpty(Q))
    {
        height++;
        int size = (Q.rear - Q.front + MaxSize) % MaxSize;
        for(int i = 0; i < size; i++)
        {
            DeQueue(Q, p);
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

    return height;
}

int HeightR(BiTree T)
{
    int height;
    int lheight, rheight;
    BiTNode * p = T;
    if(p != NULL)
    {
        lheight = HeightR(p->lchild);
        rheight = HeightR(p->rchild);
        height = lheight > rheight ? lheight : rheight;

        return height + 1;
    }
    return 0;
}

int main()
{
    BiTree T;
	T = CreatBiTreeByPre();

	PreRec(T);
	cout << endl;

    cout << Height(T) << endl;
    cout << HeightR(T) << endl;
    return 0;
}