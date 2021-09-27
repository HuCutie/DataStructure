#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

void Delete(BiTree & T)
{
    BiTNode * p = T;
    if(p != NULL)
    {
        Delete(p->lchild);
        Delete(p->rchild);
        free(p);
    }
}

void DeleteX(BiTree & T, SqQueue Q, ElemType x)
{
    InitQueue(Q);
    BiTNode * p = T;

    if(T->data == x)
    {
        Delete(T);
        T = NULL;
        return ;
    }

    if(p != NULL)
    {
        EnQueue(Q, p);
        while (!QueueEmpty(Q))
        {
            DeQueue(Q, p);
            if (p->lchild != NULL)
            {
                if (p->lchild->data == x)
                {
                    Delete(p->lchild);
                    p->lchild = NULL;
                }
                else
                {
                    EnQueue(Q, p->lchild);
                }
            }
            if (p->rchild != NULL)
            {
                if (p->rchild->data == x)
                {
                    Delete(p->rchild);
                    p->rchild = NULL;
                }
                else
                {
                    EnQueue(Q, p->rchild);
                }
            }
        }
    }
}

int main()
{
    BiTree T;
    ElemType x;
    SqQueue Q;
	T = CreatBiTreeByPre();

	PreRec(T);
	cout << endl;

    cin >> x;
    DeleteX(T, Q, x);
    PreRec(T);
	cout << endl;
    return 0;
}