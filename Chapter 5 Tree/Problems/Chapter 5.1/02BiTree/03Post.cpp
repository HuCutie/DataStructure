#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

void Post(BiTree T, SqStack S)
{
    InitStack(S);
    BiTNode * p = T;
    BiTNode * pre = NULL;

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
            if(p->rchild == NULL && p != pre)
            {
                p = p->rchild;
            }
            else
            {
                Pop(S, p);
                cout << p->data << " ";
                pre = p;
                p = NULL;
            }
        }
    }
}

int main()
{
    BiTree T;
	T = CreatBiTreeByPre();
	SqStack S;

	PosRec(T);
	cout << endl;
	Pos(T, S);
	cout << endl;
    Post(T, S);
	cout << endl;

    return 0;
}