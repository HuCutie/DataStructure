#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 3 Stack and Queue\lib\Queue.cpp"
#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 3 Stack and Queue\lib\Stack.cpp"

void ReverseQueue(SqQueue & Q, SqStack S)
{
    ElemType x;
    int size = 0;
    while(!QueueEmpty(Q))
    {
        DeQueue(Q, x);
        Push(S, x);
    }

    while(!StackEmpty(S))
    {
        Pop(S, x);
        EnQueue(Q, x);
    }
}

int main()
{
    SqQueue Q;
    SqStack S;
    ElemType x;

    InitQueue(Q);
    InitStack(S);

    for(int i = 0; i < 5; i++)
    {
        cin >> x;
        EnQueue(Q, x);
    }

    ReverseQueue(Q, S);

    for(int i = 0; i < 5; i++)
    {
        DeQueue(Q, x);
        cout << x << " ";
    }
    cout << endl;

    return 0;
}