#define MaxSize 100

typedef struct
{
    int data[MaxSize];
    int top;
}SqStack;

typedef struct
{
    int data[MaxSize];
    int front, rear;
}SqQueue;