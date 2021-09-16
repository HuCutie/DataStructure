#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\SqList.cpp"

void Reverse(SqList &L, int start, int end)
{
    int count = (end-start) / 2;
    ElemType temp;
    if(start < 0 || end > L.length - 1 || start >= end)
    {
        cout << "Invalid range." << endl;
        return ;
    }
    if(L.length == 0)
    {
        cout << "Empty list." << endl;
        return ;
    }
    for(int i = 0; i <= count; i++)
    {
        temp = L.data[start+i];
        L.data[start+i] = L.data[end-i];
        L.data[end-i] = temp;
    }
}

void ListReverse(SqList &L, int m, int n)
{
    Reverse(L, 0, m-1);
    Reverse(L, m, m+n-1);
    Reverse(L, 0, m+n-1);
}

int main()
{
    SqList L;
    ListInit(L, 17);
    ListPrint(L);

    ListReverse(L, 7, 10);
    ListPrint(L);

    return 0;
}