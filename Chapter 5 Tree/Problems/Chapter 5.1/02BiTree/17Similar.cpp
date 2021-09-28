#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

bool Similar(BiTree T1, BiTree T2)
{
    if(T1 == NULL && T2 == NULL)
    {
        return true;
    }
    
    if(T1 == NULL || T2 == NULL)
    {
        return false;
    }

    return (Similar(T1->lchild, T2->lchild)) && (Similar(T1->rchild, T2->rchild));
}

int main()
{
    BiTree T1;
	T1 = CreatBiTreeByPre();

	PreRec(T1);
	cout << endl;

    BiTree T2;
	T2 = CreatBiTreeByPre();

	PreRec(T2);
	cout << endl;
    
    cout << Similar(T1, T2) << endl;

    return 0;
}