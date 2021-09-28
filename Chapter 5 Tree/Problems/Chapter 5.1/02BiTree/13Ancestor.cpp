#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

BiTNode * Ancestor(BiTree T, BiTNode * p, BiTNode * q)
{
    if(T == NULL || T == p || T == q)
    {
        return T;
    }

    BiTNode * L = Ancestor(T->lchild, p, q);
    BiTNode * R = Ancestor(T->rchild, p, q);

    return L != NULL && R != NULL ? T : L == NULL ? R : L;
}

int main()
{
    BiTree T;
    BiTNode * p, * q, * r;
	T = CreatBiTreeByPre();

	PreRec(T);
    cout << endl;

    p = T->lchild->rchild;
    q = T->lchild->rchild->rchild;
    r = Ancestor(T, p, q);
    cout << r << " " << r->data << endl;

    return 0;
}