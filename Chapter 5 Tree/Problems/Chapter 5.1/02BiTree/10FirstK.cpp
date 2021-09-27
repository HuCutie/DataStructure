#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

int static num = 1;

BiTNode * FirstK(BiTree T, int k)
{
    BiTNode * p = T;
    BiTNode * q;

    if(p == NULL)
    {
        return NULL;
    }

    if(num == k)
    {
        return p;
    }

    num++;
    q = FirstK(T->lchild, k);
    if(q != NULL)
    {
        return q;
    }
    q = FirstK(T->rchild, k);
    if(q != NULL)
    {
        return q;
    } 
}

int main()
{
    BiTree T;
    BiTNode * p;
	T = CreatBiTreeByPre();

	PreRec(T);
	cout << endl;

    p = FirstK(T, 3);
    cout << p << " " << p->data << endl;

    return 0;
}