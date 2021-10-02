#include <iostream>

using namespace std;

#define level 3

#define ElemType int

typedef struct BNode
{
    int num;
    ElemType data[level-1];
    struct BNode * child[level];
    bool isLeaf;
} BNode, * BTree;