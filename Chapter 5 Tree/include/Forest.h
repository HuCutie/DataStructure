#include <iostream>

using namespace std;

#define MaxSize 100
#define ElemType char

typedef struct
{
    ElemType data;
    int parent;
}PTnode;

typedef struct
{
    PTnode nodes[MaxSize];
    int n;
}PTree;

typedef struct CSNode
{
    ElemType data;
    CSNode * firstChile, * nextSibling;
}CSNode, * CSTree;
