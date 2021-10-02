#include <iostream>

using namespace std;

#define MaxVertexNum 100

typedef char VertexType;
typedef int EdgeType;

typedef struct
{
    VertexType Vex[MaxVertexNum];
    EdgeType edge[MaxVertexNum][MaxVertexNum];

    int VexNum;
    int ArcNum;
} MGraph;
