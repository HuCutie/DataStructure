#include <iostream>
#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 6 Graph\include\StackAndQueue.h"

using namespace std;

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

bool Push(SqStack & S, int p)
{
    if(S.top == MaxSize - 1)
    {
        cout << "Stack is full." << endl;
        return false;
    }
    S.data[++S.top] = p;
    return true;
}

bool Pop(SqStack & S, int & p)
{
    if(S.top == -1)
    {
        cout << "Stack is full." << endl;
        return false;
    }
    p = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, int & p)
{
    if(S.top == -1)
    {
        cout << "Stack is empty." << endl;
        return false;
    }
    p = S.data[S.top];
    return true;
}

void InitQueue(SqQueue & Q)
{
    Q.front = 0;
    Q.rear = 0;
}

bool QueueEmpty(SqQueue Q)
{
    if(Q.rear == Q.front)
    {
        return true;
    }
    return false;
}

bool EnQueue(SqQueue & Q, int p)
{
    if((Q.rear + 1) % MaxSize == Q.front)
    {
        cout << "Queue is full." << endl;
        return false;
    }
    Q.data[Q.rear] = p;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue & Q, int & p)
{
    if(Q.rear == Q.front)
    {
        cout << "Queue is empty." << endl;
        return false;
    }
    p = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}