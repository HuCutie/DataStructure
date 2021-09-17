#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\SqList.cpp"

ElemType MainElem(SqList L)
{
    ElemType e = L.data[0];
    int count = 1;
    for(int i = 1; i < L.length; i++)
    {
        if(L.data[i] == e)
        {
            count++;
        }
        else
        {
            if(count > 0)
            {
                count--;
            }
            else
            {
                e = L.data[i];
                count = 1;
            }
        }
    }

    if(count > 0)
    {
        count = 0;
        for(int i = 0; i < L.length; i++)
        {
            if(L.data[i] == e)
            {
                count++;
            }
        }
    }

    if(count > L.length / 2)
    {
        return e;
    }
    return -1;
}

int main()
{
    SqList L;
    ListInit(L, 8);
    for(int i = 0; i < L.length; i++)
    {
        cin >> L.data[i];
    }
    ListPrint(L);

    cout << MainElem(L) << endl;

    return 0;
}