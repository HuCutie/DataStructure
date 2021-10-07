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
        if(!visitedL[GetIndexByData(G, G.vertices[p->adjvex].data)])
        {
            cout << G.vertices[p->adjvex].data << " ";
            visitedL[p->adjvex] = true;
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

void BFS(ALGraph G, SqQueue Q, int index)
{
    ArcNode * p;

    cout << G.vertices[index].data << " ";
    visitedL[index] = true;

    EnQueue(Q, index);

    while(!QueueEmpty(Q))
    {
        DeQueue(Q, index);
        p = G.vertices[index].first;

        while(p != NULL)
        {
            if(!visited[p->adjvex])
            {
                cout << G.vertices[p->adjvex].data << " ";
                visited[p->adjvex] = true;

                EnQueue(Q, p->adjvex);
            }

            p =p->next;
        }
    }
}