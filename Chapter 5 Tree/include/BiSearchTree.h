#include <iostream>

using namespace std;

#define ElemType int

typedef struct BSNode
{
    ElemType data;
    BSNode * lchild, * rchild;

    int count = 0;
}BSNode, * BSTree;