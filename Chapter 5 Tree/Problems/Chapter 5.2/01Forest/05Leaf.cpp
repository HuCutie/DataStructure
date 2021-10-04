#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\Forest.cpp"

int static num = 0;
void Leaf(CSTree T)
{
    if(T != NULL)
    {
        if(T->firstChild == NULL)
        {
            num++;
        }
        
        Leaf(T->firstChild);
        Leaf(T->nextSibling);
    }
}

int main()
{
    CSTree T = Create();

    Pre(T);
    cout << endl;

    Leaf(T);
    cout << num << endl;

    return 0;
}