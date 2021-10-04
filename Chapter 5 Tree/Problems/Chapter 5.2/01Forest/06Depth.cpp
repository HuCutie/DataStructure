#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\Forest.cpp"

int Depth(CSTree T)
{
    int depth = 0;

    if(T != NULL)
    {
        if(T->firstChild != NULL)
        {
            depth++;
        }

        int l = Depth(T->firstChild);
        int r = Depth(T->nextSibling);

        return depth += (l > r ? l : r);
    }
    return 0;
}

int main()
{
    // RA#E##B#CFG#H#K####
    CSTree T = Create();

    Pre(T);
    cout << endl;

    cout << Depth(T) + 1 << endl;

    return 0;
}