#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

void Swap(BiTree & T)
{
    if(T !=NULL)
    {
        Swap(T->lchild);
        Swap(T->rchild);

        BiTNode * t;
        t = T->lchild;
        T->lchild = T->rchild;
        T->rchild = t;
    }
}

int main()
{
    BiTree T;
	T = CreatBiTreeByPre();

	PreRec(T);
	cout << endl;

    Swap(T);

    PreRec(T);
	cout << endl;
    return 0;
}