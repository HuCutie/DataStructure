#include <iostream>

using namespace std;

#define ElemType char
#define MaxSize 50

typedef struct BiTNode
{
    ElemType data;
    BiTNode * lchild, * rchild;
}BiTNode, * BiTree;

typedef struct
{
    BiTNode * data[MaxSize];
    int top;
}SqStack;

typedef struct
{
    BiTNode * data[MaxSize];
    int front, rear;
}SqQueue;

BiTree CreatBiTreeByPre();

void PreRec(BiTree T);
void MidRec(BiTree T);
void PosRec(BiTree T);

void Pre(BiTree T, SqStack S);
void Mid(BiTree T, SqStack S);
void Pos(BiTree T, SqStack S);
void Hir(BiTree T, SqQueue Q);