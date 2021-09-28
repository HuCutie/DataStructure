#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

int Width(BiTree T, SqQueue Q)
{
    BiTNode * p = T;
    int width = 1;
    int currentWidth = 1;
    
    InitQueue(Q);
    EnQueue(Q, p);

    while(!QueueEmpty(Q))
    {
        while(currentWidth != 0)
        {
            DeQueue(Q, p);
            if (p->lchild != NULL)
            {
                EnQueue(Q, p->lchild);
            }
            if (p->rchild != NULL)
            {
                EnQueue(Q, p->rchild);
            }

            currentWidth--;
        }

        currentWidth = (Q.rear - Q.front + MaxSize) % MaxSize;

        width = currentWidth > width ? currentWidth : width;
    }

    return width;
}

int main()
{
    BiTree T;
	T = CreatBiTreeByPre();
	SqQueue Q;

	PreRec(T);
	cout << endl;

    cout << Width(T, Q) << endl;

    return 0;
}