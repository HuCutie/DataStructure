#include <iostream>

using namespace std;

#define MaxVextexNum 100

typedef char VertexType;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode * next;
} ArcNode;

typedef struct VNode
{
    VertexType data;
    ArcNode * first;
} VNode, AdjList[MaxVextexNum];

typedef struct
{
    AdjList vertices;
    int VexNum;
    int ArcNum;
} ALGraph;