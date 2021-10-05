#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiSearchTree.cpp"

void PrintNotSmallThanK(BSTree T, ElemType k)
{
    if(T != NULL)
    {
        PrintNotSmallThanK(T->lchild, k);

        if(T->data >= k)
        {
            cout << T->data << " ";
        }

        PrintNotSmallThanK(T->rchild, k);
    }
}

int main()
{
    BSTree T = Create(5);
    Print(T);
    cout << endl;

    PrintNotSmallThanK(T, 3);

    return 0;
}