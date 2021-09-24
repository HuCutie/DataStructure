#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 3 Stack and Queue\include\Stack.h"

void InitStack(SqStack & S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    if(S.top == -1)
    {
        return true;
    }
    return false;
}

bool Push(SqStack & S, ElemType x)
{
    if(S.top == MaxSize - 1)
    {
        cout << "Stack is full." << endl;
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack & S, ElemType & x)
{
    if(S.top == -1)
    {
        cout << "Stack is full." << endl;
        return false;
    }
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, ElemType & x)
{
    if(S.top == -1)
    {
        cout << "Stack is full." << endl;
        return false;
    }
    x = S.data[S.top];
    return true;
}

void InitSharedStack(SharedStack & S)
{
    S.top[0] = -1;
    S.top[1] = MaxSize;
}