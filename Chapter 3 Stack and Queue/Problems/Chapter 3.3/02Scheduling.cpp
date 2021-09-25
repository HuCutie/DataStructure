#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 3 Stack and Queue\lib\Stack.cpp"

void Scheduling(SqStack & S, ElemType * seq)
{
    ElemType x;
    for(int i = 0; i < 7; i++)
    {
        if(seq[i] == 1)
        {
            cout << seq[i] << " ";
            continue;
        }
        Push(S, seq[i]);
    }

    while(!StackEmpty(S))
    {
        Pop(S, x);
        cout << x << " ";
    }
}

int main()
{
    ElemType * seq = (ElemType *)malloc(sizeof(ElemType) * 7);
    SqStack S;

    InitStack(S);

    for(int i = 0; i < 7; i++)
    {
        cin >> seq[i];
    }

    Scheduling(S, seq);

    return 0;
}