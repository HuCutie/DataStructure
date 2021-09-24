#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 3 Stack and Queue\include\Queue.h"

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

bool EnQueue(SqQueue & Q, ElemType x)
{
    if((Q.rear + 1) % MaxSize == Q.front)
    {
        cout << "Queue is full." << endl;
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue & Q, ElemType & x)
{
    if(Q.rear == Q.front)
    {
        cout << "Queue is empty." << endl;
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

void InitLQueue(LinkQueue & Q)
{
    QLinkNode * head = (QLinkNode *)malloc(sizeof(QLinkNode));
    Q.front = head;
    Q.rear = head;
}

bool LQueueEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
    {
        return true;
    }
    return false;
}

void EnLQueue(LinkQueue & Q, ElemType x)
{
    QLinkNode * q = (QLinkNode *)malloc(sizeof(QLinkNode));
    q->data = x;
    q->next = NULL;
    Q.rear->next = q;
    Q.rear = q;
}

bool DeLQueue(LinkQueue & Q, ElemType & x)
{
    if(Q.front == Q.rear)
    {
        cout << "Queue is empty." << endl;
        return false;
    }
    QLinkNode * q = Q.front->next;
    x = q->data;
    if(Q.rear == q)
    {
        Q.rear = Q.front;
    }
    free(q);
    return true;
}