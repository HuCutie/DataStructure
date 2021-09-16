#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\SqList.cpp"

void DeleteFromUNOL(SqList &L, ElemType s, ElemType t)
{
    int count = 0;
    if(s >= t)
    {
        cout << "Illegal range." << endl;
        return ;
    }
    if(L.length == 0)
    {
        cout << "Empty list." << endl;
        return ;
    }
    for(int i = 0; i < L.length; i++)
    {
        if(count > 0)
        {
            L.data[i - count] = L.data[i];
        }
        if(L.data[i] > s && L.data[i] < t)
        {
            count++;
        }
    }
    L.length -= count;
}

int main()
{
    SqList L;
    ListInit(L, 10);
    ListPrint(L);

    DeleteFromUNOL(L, 10, 40);
    ListPrint(L);

    return 0;
}