#include <iostream>

using namespace std;

#define ElemType char

typedef struct ThreadNode
{
    ElemType data;
    ThreadNode * lchild, * rchild;
    int ltag, rtag;
}ThreadNode, * ThreadBiTree;