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

void LeftShift(SqList &L, int p)
{
    Reverse(L, 0, p-1);
    Reverse(L, p, L.length-1);
    Reverse(L, 0, L.length-1);
}

int main()
{
    SqList L;
    ListInit(L, 10);
    ListPrint(L);

    LeftShift(L, 3);
    ListPrint(L);

    return 0;
}