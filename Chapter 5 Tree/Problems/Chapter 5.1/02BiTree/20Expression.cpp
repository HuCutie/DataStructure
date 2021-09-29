#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

void Expression(BiTree T, int depth)
{
    BiTNode * p = T;

    if(p == NULL)
    {
        return ;
    }
    else if(p->lchild == NULL && p->rchild == NULL)
    {
        cout << p->data;
    }
    else
    {
        if(depth > 1)
        {
            cout << "(";
        }
        Expression(T->lchild, depth+1);
        cout << p->data;
        Expression(T->rchild, depth+1);
        if(depth > 1)
        {
            cout << ")";
        }
    }
}

int main()
{
    BiTree T;
	T = CreatBiTreeByPre();
	SqStack S;
	SqQueue Q;

	PreRec(T);
	cout << endl;

    Expression(T, 1);
    return 0;
}