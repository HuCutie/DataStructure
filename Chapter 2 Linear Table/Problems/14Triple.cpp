#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\SqList.cpp"

int abs(int a)
{
    if(a > 0)
    {
        return a;
    }
    return -a;
}

ElemType Triple(SqList L1, SqList L2, SqList L3)
{
    int min;
    int result = INT_MAX;
    int i = 0, j = 0, k = 0;
    while(i < L1.length && j < L2.length && k < L3.length)
    {
        min = abs(L1.data[i] - L2.data[j]) + abs(L2.data[j] - L3.data[k]) + abs(L3.data[k] - L1.data[i]);
        if(min < result)
        {
            result = min;
        }
        if(L1.data[i] <= L2.data[j] && L1.data[i] <= L3.data[k])
        {
            i++;
        }
        else if(L2.data[j] <= L1.data[i] && L2.data[j] <= L3.data[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    return result;
}

int main()
{
    SqList L1;
    ListInit(L1, 3);
    for(int i = 0; i < L1.length; i++)
    {
        cin >> L1.data[i];
    }
    ListPrint(L1);

    SqList L2;
    ListInit(L2, 4);
    for(int i = 0; i < L2.length; i++)
    {
        cin >> L2.data[i];
    }
    ListPrint(L2);

    SqList L3;
    ListInit(L3, 5);
    for(int i = 0; i < L3.length; i++)
    {
        cin >> L3.data[i];
    }
    ListPrint(L3);

    cout << Triple(L1, L2, L3) << endl;

    return 0;
}