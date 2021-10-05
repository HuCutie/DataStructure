#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

int GetDepth(BiTree T)
{
    if(T == NULL)
    {
        return 0;
    }

    int l = GetDepth(T->lchild);
    int r = GetDepth(T->rchild);

    return l > r ? l+1 : r+1;
}

int GetDiffer(BiTree T)
{
    if(T == NULL)
    {
        return 0;
    }
    int l = GetDepth(T->lchild);
    int r = GetDepth(T->rchild);
    
    return l - r;
}

bool isBalancedTree(BiTree T)
{
    int diff = GetDiffer(T);
    if(diff > 1 || diff < -1)
    {
        return false;
    }
    else
    {
        return true;
    }

    return isBalancedTree(T->lchild) && isBalancedTree(T->rchild);
}

int main()
{
    BiTree T = CreatBiTreeByPre();
    PreRec(T);
    cout << endl;

    cout << isBalancedTree(T) << endl;
    return 0;
}