#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\Forest.cpp"

CSTree CreateT (ElemType seq[], int degree[], int n)
{
    CSTree T;
    CSNode * p = new CSNode[n];
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        p[i].data = seq[i];
        p[i].firstChild = NULL;
        p[i].nextSibling = NULL;
    }

    for(int i = 0; i < n; i++)
    {
        int deg = degree[i];
        if(deg != 0)
        {
            count++;
            p[i].firstChild = &p[count];
            
            for(int j = 2; j <= deg; j++)
            {
                count++;
                p[count-1].nextSibling = &p[count];
            }
        }
    }

    T = p;

    return T;
}

int main()
{
    // RAD#E##B#CFG#H#K#####
    CSTree T1 = Create();

    ElemType seq[10] = {'R', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'K'};
    int degree[10] = {3, 2, 0, 1, 0, 0, 3, 0, 0, 0};

    CSTree T = CreateT(seq, degree, 10);

    Pre(T1);
    cout << endl;

    Pre(T);
    cout << endl;

    return 0;
}