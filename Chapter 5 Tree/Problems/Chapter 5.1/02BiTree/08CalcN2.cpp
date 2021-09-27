#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

int CalcN2(BiTree T)
{
    if(T == NULL)
    {
        return 0;
    }
    else if(T->lchild != NULL && T->rchild != NULL)
    {
        return CalcN2(T->lchild) + CalcN2(T->rchild) + 1;
    }
    else
    {
        return CalcN2(T->lchild) + CalcN2(T->rchild);
    }
}

int main()
{
    BiTree T;
	T = CreatBiTreeByPre();

	PreRec(T);
	cout << endl;

    cout << CalcN2(T) << endl;
    return 0;
}