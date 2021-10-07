#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 6 Graph\include\ALGraph.h"
#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 6 Graph\lib\StackAndQueue.cpp"


int GetIndexByData(ALGraph G, VertexType x)
{
    for(int i = 0; i < G.VexNum; i++)
    {
        if(G.vertices[i].data == x)
        {
            return i;
        }
    }

    return -1;
}

void InitALGraph(ALGraph & G)
{
    cout << "Input the number of vertices: ";
    cin >> G.VexNum;

    cout << "Input each vertex: " << endl;
    for(int i = 0; i < G.VexNum; i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].first = NULL;
    }

    G.ArcNum = 0;
}

ALGraph Create()
{
    ALGraph G;
    ArcNode * p;
    VertexType temp;

    InitALGraph(G);

    for(int i = 0; i < G.VexNum; i++)
    {

        while (1)
        {
            cout << "Input the end node starting whith " << G.vertices[i].data << " (# stands for NULL) : ";
            cin >> temp;

            if (temp == '#')
            {
                break;
            }
            else
            {
                int index = GetIndexByData(G, temp);
                if (index != -1)
                {
                    p = (ArcNode *)malloc(sizeof(ArcNode));

                    p->adjvex = index;
                    p->next = G.vertices[i].first;
                    G.vertices[i].first = p;

                    G.ArcNum++;
                }
                else
                {
                    cout << "Wrong node, please input again." << endl;
                    continue;
                }
            }
        }
    }

    return G;
}

int FirstNeighbor(ALGraph G, VertexType x)
{
    ArcNode * p;
    int i;

    i = GetIndexByData(G, x);

    if(i == -1)
    {
        cout << "The vertex is not in the graph." << endl;
        return -1;
    }

    p = G.vertices[i].first;
    if(p != NULL)
    {
        return p->adjvex;
    }

    return -1;
}

int NextNeighbor(ALGraph G, VertexType a, VertexType b)
{
    ArcNode * p;
    int i, j;

    i = GetIndexByData(G, a);
    j = GetIndexByData(G, b);

    if(i == -1 || j == -1)
    {
        cout << "Wrong node." << endl;
        return -1;
    }

    p = G.vertices[i].first->next;
    if(p != NULL)
    {
        return p->adjvex;
    }

    return -1;
}

bool visitedL[MaxVextexNum];
void InitVisited()
{
    for(int i = 0; i < MaxVextexNum; i++)
    {
        visitedL[i] = false;
    }
}

void DFS(ALGraph G, int index)
{
    ArcNode * p;

    cout << G.vertices[index].data << " ";
    visitedL[index] = true;

    p = G.vertices[index].first;
    while(p != NULL)
    {
        if(!visitedL[p->adjvex])
        {
            DFS(G, p->adjvex);
        }
        p = p->next;
    }
}

void DFSTravel(ALGraph G)
{
    InitVisited();
    for(int i = 0; i < G.VexNum; i++)
    {
        if(!visitedL[i])
        {
            DFS(G, i);
        }
    }
}

void DFS(ALGraph G, SqStack S, int index)
{
    int temp;
    ArcNode * p;

    InitVisited();

    Push(S, index);
    visitedL[index] = true;

    while(!StackEmpty(S))
    {
        Pop(S, temp);
        cout << G.vertices[temp].data << " ";

        p = G.vertices[temp].first;
        while(p != NULL)
        {
            if(!visitedL[p->adjvex])
            {
                Push(S, p->adjvex);
                visitedL[p->adjvex] = true;
            }
            p = p->next;
        }
    }
}

void BFSTravel(ALGraph G)
{
    ArcNode * p;
    SqQueue Q;

    InitVisited();
    InitQueue(Q);

    for(int i = 0; i < G.VexNum; i++)
    {
        if(!visitedL[i])
        {
            visitedL[i] = true;
            EnQueue(Q, i);

            cout << G.vertices[i].data << " ";
            while(!QueueEmpty(Q))
            {
                DeQueue(Q, i);
                p = G.vertices[i].first;

                while(p != NULL)
                {
                    if(!visitedL[p->adjvex])
                    {
                        visitedL[p->adjvex] = true;
                        cout << G.vertices[p->adjvex].data << " ";

                        EnQueue(Q, p->adjvex);
                    }

                    p = p->next;
                }
            }
        }
    }
}