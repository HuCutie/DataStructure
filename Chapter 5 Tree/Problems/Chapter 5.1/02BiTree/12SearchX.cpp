#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

bool SearchX(BiTree T, ElemType x)
{
    if(T == NULL)
    {
        return false;
    }

    if(T->data == x)
    {
        return true;
    }

    if(SearchX(T->lchild, x) || SearchX(T->rchild, x))
    {
        cout << T->data << " ";
        return true;
    }

    return false;
}

int main()
{
    BiTree T;
	T = CreatBiTreeByPre();
	SqStack S;

	PosRec(T);
	cout << endl;

    SearchX(T, 'e');
	cout << endl;
    return 0;
}