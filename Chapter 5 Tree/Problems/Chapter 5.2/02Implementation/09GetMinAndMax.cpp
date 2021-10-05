#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiSearchTree.cpp"

void GetMinAndMax(BSTree T)
{
    BSNode * p = T;
    BSNode * q = T;

    while(p->lchild != NULL)
    {
        p = p->lchild;
    }

    while(q->rchild != NULL)
    {
        q = q->rchild;
    }

    cout << "Min: " << p->data << " Addr: " << p << endl;
    cout << "Max: " << q->data << " Addr: " << q << endl;
}

int main()
{
    BSTree T = Create(5);
    Print(T);
    cout << endl;

    GetMinAndMax(T);

    return 0;
}