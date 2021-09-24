#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 3 Stack and Queue\lib\Queue.cpp"

void Init(SqQueue & Q)
{
    Q.tag = 0;
}

bool IsEmpty(SqQueue Q)
{
    if(Q.front == Q.rear && Q.tag == 0)
    {
        return true;
    }
    return false;
}

bool EnTQueue(SqQueue & Q, ElemType x)
{
    if(Q.front == Q.rear && Q.tag == 1)
    {
        cout << "Queue is full." << endl;
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1) % MaxSize;

    if(Q.rear == Q.front)
    {
        Q.tag = 1;
    }
    return true;
}

bool DeTQueue(SqQueue & Q, ElemType & x)
{
    if(Q.front == Q.rear && Q.tag == 0)
    {
        cout << "Queue is empty." << endl;
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;

    if(Q.front == Q.rear)
    {
        Q.tag = 0;
    }
    return true;
}

int main()
{
    SqQueue Q;
    ElemType x;
    InitQueue(Q);
    Init(Q);
    cout << IsEmpty(Q) << endl;
    DeTQueue(Q, x);
    EnTQueue(Q, 999);

    DeTQueue(Q, x);
    cout << x << endl;
    return 0;
}