#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 3 Stack and Queue\lib\Queue.cpp"

void Scheduling2(SqQueue & Q, SqQueue & Q1, SqQueue & Q2)
{
    ElemType x;
    int i = 0;
    int count = 0;

    while(i < 10)
    {
        if (QueueEmpty(Q1) && QueueEmpty(Q2))
        {
            cout << "No vehicles in the waiting area." << endl;
            i = 11;
        }

        if(!QueueEmpty(Q1) && count < 4)
        {
            DeQueue(Q1, x);
            EnQueue(Q, x);

            count++;
            i++;
        }
        else if(!QueueEmpty(Q2) && count == 4)
        {
            DeQueue(Q2, x);
            EnQueue(Q, x);

            count = 0;
            i++;
        }
        else
        {
            while(i < 10 && count < 4 && !QueueEmpty(Q2))
            {
                DeQueue(Q2, x);
                EnQueue(Q, x);

                count++;
                i++;
            }
            count = 0;
        }
    }

    while(!QueueEmpty(Q))
    {
        DeQueue(Q, x);
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int len1;
    int len2;

    cin >> len1 >> len2;

    ElemType * seq0 = (ElemType *)malloc(sizeof(ElemType) * len1);
    ElemType * seq1 = (ElemType *)malloc(sizeof(ElemType) * len2);

    SqQueue Q;
    InitQueue(Q);
    SqQueue Q1;
    InitQueue(Q1);
    SqQueue Q2;
    InitQueue(Q2);

    for(int i = 0; i < len1; i++)
    {
        cin >> seq0[i];
        EnQueue(Q1, seq0[i]);
    }
    for(int i = 0; i < len2; i++)
    {
        cin >> seq1[i];
        EnQueue(Q2, seq1[i]);
    }

    Scheduling2(Q, Q1, Q2);

    return 0;
}