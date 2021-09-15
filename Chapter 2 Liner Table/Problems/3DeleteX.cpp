#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Liner Table\lib\SqList.cpp"

void DeleteX(SqList &L, ElemType x)
{
    int count = 0;
    for(int i = 0; i < L.length; i++)
    {
        L.data[i - count] = L.data[i];
        if(L.data[i] == x)
        {
            count++;
        }        
    }
    L.length -= count;
}

int main()
{
    SqList L;
    L.length = 10;
    for(int i = 0; i < 10; i++)
    {
        if(i % 2 == 0)
        {
            L.data[i] = 5;
        }
        else
        {
            L.data[i] = 1;
        }        
    }
    ListPrint(L);

    DeleteX(L, 5);
    ListPrint(L);

    return 0;
}