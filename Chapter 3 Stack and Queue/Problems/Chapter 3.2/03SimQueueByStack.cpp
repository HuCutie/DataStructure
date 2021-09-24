#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 3 Stack and Queue\lib\Stack.cpp"

bool StackOverFlow(SqStack S)
{
    if(S.top == MaxSize - 1)
    {
        return true;
    }
    return false;
}

bool QueueEmpty(SqStack S1, SqStack S2)
{
    return (StackEmpty(S1) && StackEmpty(S2)) ? true : false;
}

bool EnQueue(SqStack & S1, SqStack & S2, ElemType x)
{
    ElemType t;
    if(StackOverFlow(S1) && !StackEmpty(S2))
    {
        cout << "Queue is full." << endl;
        return false;
    }

    if(!StackOverFlow(S1))
    {
        Push(S1, x);
        return true;
    }

    if(StackOverFlow(S1) && StackEmpty(S2))
    {
        while(!StackEmpty(S1))
        {
            Pop(S1, t);
            Push(S2, t);
        }
        Push(S1, x);
        return true;
    }

    return false;
}

bool DeQueue(SqStack & S1, SqStack & S2, ElemType & x)
{
    ElemType t;
    if(StackEmpty(S1) && StackEmpty(S2))
    {
        cout << "Queue is empty." << endl;
        return false;
    }

    if(!StackEmpty(S2))
    {
        Pop(S2, x);
        return true;
    }
    else
    {
        while(!StackEmpty(S1))
        {
            Pop(S1, t);
            Push(S2, t);
        }
        Pop(S2, x);
        return true;
    }

    return false;
}

int main()
{
    SqStack S1;
    SqStack S2;
    ElemType x;

    InitStack(S1);
    InitStack(S2);

    DeQueue(S1, S2, x);

    cout << QueueEmpty(S1, S2) << endl;

    for(int i = 0; i < 100; i++)
    {
        EnQueue(S1, S2, i+1);
    }

    EnQueue(S1, S2, 999);

    for(int i = 0; i < 100; i++)
    {
        DeQueue(S1, S2, x);
        cout << x << " ";
    }
    cout << endl;

    DeQueue(S1, S2, x);

    return 0;
}