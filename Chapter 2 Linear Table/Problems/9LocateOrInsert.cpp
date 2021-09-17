#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\SqList.cpp"

void LocateOrInsert(SqList &L, ElemType e)
{
    bool isLocated = false;
    int location = 0;
    for(int i = 0; i < L.length; i++)
    {
        if(L.data[i] == e && i != L.length-1)
        {
            L.data[i] = L.data[i+1];
            L.data[i+1] = e;
            isLocated = true;            
            break;
        }        
    }    

    if(!isLocated)
    {
        for (int i = 0; i < L.length - 1; i++)
        {
            if (L.data[i] < e && L.data[i + 1] > e)
            {
                location = i + 1;
                break;
            }
        }

        for(int i = L.length-1; i >= location; i--)
        {
            L.data[i+1] = L.data[i];
        }
        L.data[location] = e;
        L.length++;
    }
}

int main()
{
    SqList L;
    ListInit(L, 10);
    for(int i = 0; i < 10; i++)
    {
        cin >> L.data[i];
    }
    ListPrint(L);

    LocateOrInsert(L, 4);
    ListPrint(L);

    return 0;
}