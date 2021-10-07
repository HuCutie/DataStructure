#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 6 Graph\lib\ALGraph.cpp"

void ALDFS(ALGraph G, int index)
{
    ArcNode * p;

    visitedL[index] = true;

    p = G.vertices[index].first;
    while(p != NULL)
    {
        if(!visitedL[p->adjvex])
        {
            ALDFS(G, p->adjvex);
        }
        p = p->next;
    }
}

bool isConnnectedDFS(ALGraph G, VertexType a, VertexType b)
{
    int i, j;

    i = GetIndexByData(G, a);
    j = GetIndexByData(G, b);

    InitVisited();

    if(i == -1 || j == -1)
    {
        cout << "Wrong node." << endl;
        return -1;
    }

    ALDFS(G, i);

    if(visitedL[j])
    {
        return true;
    }

    return false;
}

void ALBFS(ALGraph G, int index)
{
    ArcNode * p;
    SqQueue Q;

    InitVisited();
    InitQueue(Q);

    if (!visitedL[index])
    {
        visitedL[index] = true;
        EnQueue(Q, index);

        while (!QueueEmpty(Q))
        {
            DeQueue(Q, index);
            p = G.vertices[index].first;

            while (p != NULL)
            {
                if (!visitedL[p->adjvex])
                {
                    visitedL[p->adjvex] = true;
                    EnQueue(Q, p->adjvex);
                }

                p = p->next;
            }
        }
    }
}

bool isConnnectedBFS(ALGraph G, VertexType a, VertexType b)
{
    int i, j;
    SqQueue Q;

    i = GetIndexByData(G, a);
    j = GetIndexByData(G, b);

    InitVisited();

    if(i == -1 || j == -1)
    {
        cout << "Wrong node." << endl;
        return -1;
    }

    ALBFS(G, i);

    if(visitedL[j])
    {
        return true;
    }

    return false;
}

int main()
{
    ALGraph G = Create();
    SqQueue Q;

    DFSTravel(G);
    cout << endl;

    BFSTravel(G);
    cout << endl;

    cout << isConnnectedDFS(G, 'a', 'c') << endl;
    cout << isConnnectedBFS(G, 'a', 'c') << endl;

    return 0;
}