#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\SqList.cpp"

void ListMerge(SqList L1, SqList L2, SqList &L)
{
    int l1 = L1.length;
    int l2 = L2.length;
    int i = 0, j = 0, k = 0;
    if(l1 + l2 > L.length)
    {
        cout << "No enough sapce to merge." << endl;
        return ;
    }

    while(i < l1 && j < l2)
    {
        if(L1.data[i] < L2.data[j])
        {
            L.data[k] = L1.data[i];
            k++;
            i++;
        }
        else
        {
            L.data[k] = L2.data[j];
            k++;
            j++;
        }
    }

    if(i < l1)
    {
        for(i; i < l1; i++)
        {
            L.data[k] = L1.data[i];
            k++;
        }
    }

    if(j < l2)
    {
        for(j; j < l2; j++)
        {
            L.data[k] = L2.data[j];
            k++;
        }
    }
}

int main()
{
    SqList L1;
    ListInit(L1, 6);
    for(int i = 0; i < 6; i ++)
    {
        cin >> L1.data[i];
    }
    ListPrint(L1);

    SqList L2;
    ListInit(L2, 7);
    for(int i = 0; i < 7; i ++)
    {
        cin >> L2.data[i];
    }
    ListPrint(L2);

    SqList L;
    ListInit(L, 13);
    ListMerge(L1, L2, L);
    ListPrint(L);

    return 0;
}