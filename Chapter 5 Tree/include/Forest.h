#include <iostream>

using namespace std;

#define MaxSize 100
#define ElemType char

// Basic Node
typedef struct
{
    ElemType data;
    int parent;
}PTnode;

// Parent Notation
typedef struct
{
    PTnode nodes[MaxSize];
    int n;
}PTree;

// Child Notation
/*
    This notation uses a linked list to connect all nodes. 
*/

// Child-Sibling Notation
typedef struct CSNode
{
    ElemType data;
    CSNode * firstChile, * nextSibling;
}CSNode, * CSTree;
