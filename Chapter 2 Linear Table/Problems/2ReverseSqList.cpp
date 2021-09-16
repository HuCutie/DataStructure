#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\SqList.cpp"

void ReverseSqList(SqList &L)
{
    ElemType temp;
    if(L.length == 0)
    {
        cout << "Empty list." << endl;
        return ;
    }
    if(L.length == 1)
    {
        return ;
    }
    for(int i = 0; i < L.length / 2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}

int main()
{
    SqList L;
    ListInit(L, 10);
    ListPrint(L);

    ReverseSqList(L);
    ListPrint(L);

    ListInit(L, 11);
    ListPrint(L);

    ReverseSqList(L);
    ListPrint(L);

    return 0;
}