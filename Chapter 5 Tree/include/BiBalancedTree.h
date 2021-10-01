#include <iostream>

using namespace std;

#define ElemType int

typedef struct BBNode
{
    ElemType data;
    BBNode * lchild, * rchild;
}BBNode, * BBTree;