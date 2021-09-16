#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\SqList.cpp"

void DeleteDuplicate(SqList &L)
{
    int count = 0;
    if(L.length == 0)
    {
        cout << "Empty list." << endl;
        return ;
    }
    for(int i = 0; i < L.length - 1; i++)
    {
        if(count > 0)
        {
            L.data[i - count] = L.data[i];
        }
        if(L.data[i] == L.data[i+1])
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
    for(int i = 0; i < L.length; i++)
    {
        cin >> L.data[i];
    }
    ListPrint(L);

    DeleteDuplicate(L);
    ListPrint(L);

    return 0;
}