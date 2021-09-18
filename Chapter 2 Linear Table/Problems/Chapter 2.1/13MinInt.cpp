#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\SqList.cpp"

ElemType MinInt(SqList L)
{
    for(int i = 0; i < L.length; i++)
    {
        if(L.data[i] > 0 && L.data[L.data[i] - 1] != L.data[i])
        {
            ElemType t = L.data[i];
            L.data[i] = L.data[L.data[i] - 1];
            L.data[L.data[i] - 1] = t;
        }
    }

    for(int i = 0; i < L.length; i++)
    {
        if(L.data[i] != i+1)
        {
            return i + 1;
        }
    }
    return L.data[L.length - 1] + 1;
}

int main()
{
    SqList L;
    ListInit(L, 4);
    for(int i = 0; i < L.length; i++)
    {
        cin >> L.data[i];
    }
    ListPrint(L);

    cout << MinInt(L) << endl;

    return 0;
}