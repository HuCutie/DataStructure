#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\SqList.cpp"


ElemType MidNum(SqList L1, SqList L2)
{
    int s1 = 0, e1 = L1.length-1;
    int s2 = 0, e2 = L2.length-1;

    while(s1 != e1 || s2 != e2)
    {
        int m1 = (s1 + e1) / 2;
        int m2 = (s2 + e2) / 2;

        if(L1.data[m1] == L2.data[m2])
        {
            return L1.data[m1];
        }

        if(L1.data[m1] < L2.data[m2])
        {
            if((s1 + e1) % 2 == 0)
            {
                s1 = m1;
                e2 = m2;
            }
            else
            {
                s1 = m1 + 1;
                e2 = m2;
            }
        }
        else
        {
            if((s2 + e2) % 2 == 0)
            {
                e1 = m1;
                s2 = m2;
            }
            else
            {
                e1 = m1;
                s2 = m2 + 1;
            }
        }
    }

    return L1.data[s1] < L2.data[s2] ? L1.data[s1] : L2.data[s2];
}

int main()
{
    SqList L1;
    ListInit(L1, 5);
    for(int i = 0; i < 5; i++)
    {
        cin >> L1.data[i];
    }
    ListPrint(L1);

    SqList L2;
    ListInit(L2, 5);
    for(int i = 0; i < 5; i++)
    {
        cin >> L2.data[i];
    }
    ListPrint(L2);

    cout << MidNum(L1, L2) << endl;

    return 0;
}