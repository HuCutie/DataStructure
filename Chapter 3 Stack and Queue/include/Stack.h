#include <iostream>

using namespace std;

#define MaxSize 50
#define ElemType int

typedef struct
{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack & S);
bool StackEmpty(SqStack S);
bool Push(SqStack & S, ElemType x);
bool Pop(SqStack & S, ElemType & x);
bool GetTop(SqStack S, ElemType & x);

typedef struct LinkNode
{
    ElemType data;
    struct LinkLode * next;
} * LinkStack;

typedef struct
{
    ElemType data[MaxSize];
    int top[2];
}SharedStack;

void InitSharedStack(SharedStack & S);
bool StackEmpty(SqStack S);
bool Push(SqStack & S, ElemType x);
bool Pop(SqStack & S, ElemType & x);
bool GetTop(SqStack S, ElemType & x);