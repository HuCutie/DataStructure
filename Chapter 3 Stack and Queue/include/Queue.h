#include <iostream>

using namespace std;

#define MaxSize 50
#define ElemType int

typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
    int tag;
}SqQueue;

void InitQueue(SqQueue & Q);
bool QueueEmpty(SqQueue Q);
bool EnQueue(SqQueue & Q, ElemType x);
bool DeQueue(SqQueue & Q, ElemType & x);

typedef struct QLinkNode
{
    ElemType data;
    struct QLinkNode * next;
}QLinkNode;

typedef struct
{
    QLinkNode * front, * rear;
}LinkQueue;

void InitLQueue(LinkQueue & Q);
bool LQueueEmpty(LinkQueue Q);
void EnLQueue(LinkQueue & Q, ElemType x);
bool DeLQueue(LinkQueue & Q, ElemType & x);
