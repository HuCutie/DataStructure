#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

    ElemType p;
bool isBiSearchTree(BiTree T)
{
    if(T == NULL)
    {
        return true;
    }

    bool l = isBiSearchTree(T->lchild);
    if(!l || p > T->data)
    {
        return false;
    }
    p = T->data;
    bool r = isBiSearchTree(T->rchild);    

    return r;
}

int main()
{
    BiTree T = CreatBiTreeByPre();
    PreRec(T);
    cout << endl;

    cout << isBiSearchTree(T) << endl;

    return 0;
}