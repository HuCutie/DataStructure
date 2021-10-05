#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiSearchTree.cpp"

int GetLevel(BSTree T, BSNode * p)
{
    int level = 0;

    if(p == NULL)
    {
        cout << "Invalid node." << endl;
        return -1;
    }

    if(T != NULL)
    {
        level++;
        while(T->data != p->data)
        {
            if(T->data < p->data)
            {
                T = T->rchild;
            }
            else if(T->data > p->data)
            {
                T = T->lchild;
            }

            level++;
        }
    }

    return level;
}

int main()
{
    BSTree T = Create(5);
    Print(T);
    cout << endl;

    cout << GetLevel(T, T->rchild);

    return 0;
}