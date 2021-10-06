#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\Forest.cpp"

int Depth(CSTree T)
{
    if(T != NULL)
    {
        int l = Depth(T->firstChild);
        int r = Depth(T->nextSibling);

        if(l+1 > r)
        {
            return l+1;
        }

        return r;
    }
    return 0;
}

int main()
{
    // RA#E##B#CFG#H#K####
    CSTree T = Create();

    Pre(T);
    cout << endl;

    cout << Depth(T) << endl;

    return 0;
}