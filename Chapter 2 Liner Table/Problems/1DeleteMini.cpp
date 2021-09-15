#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Liner Table\lib\SqList.cpp"

ElemType DeleteMini(SqList &L)
{
    int mini = L.data[0];
    int guard;
    if(L.length == 0)
    {
        cout << "Empty list." << endl;
        return NULL;
    }
    for(int i = 1; i < L.length; i++)
    {
        if(L.data[i] < mini)
        {
            mini = L.data[i];
            guard = i;
        }
    }
    L.data[guard] = L.data[L.length-1];
    L.length--;
    return mini;
}

int main()
{
    SqList L;
    ListInit(L, 10);
    ListPrint(L);

    ElemType e = DeleteMini(L);
    cout << e << endl;

    ListPrint(L);

    return 0;
}