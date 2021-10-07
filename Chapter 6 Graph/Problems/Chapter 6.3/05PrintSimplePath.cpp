#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 6 Graph\lib\ALGraph.cpp"

void PrintPath(VertexType * path, VertexType end, int length)
{   
    cout << path[0] << "->";
    for(int i = 1; i < length; i++)
    {
        cout << path[i] << "->";
    }
    cout << end;
    cout << endl;
}

void PrintSimplePath(ALGraph G, VertexType a, VertexType b, VertexType * path, int length)
{ 
    ArcNode * p;
    int i, j, temp;

    length++;

    InitVisited();
    i = GetIndexByData(G, a);
    j = GetIndexByData(G, b);

    if(i == -1 || j == -1)
    {
        cout << "Wrong node." << endl;
        return ;
    }

    path[length] = a;
    visitedL[i] = true;

    if(i == j)
    {
        PrintPath(path, b, length);
    }

    p = G.vertices[i].first;
    while(p != NULL)
    {
        if(!visitedL[p->adjvex])
        {
            PrintSimplePath(G, G.vertices[p->adjvex].data, b, path, length); 
        }

        p = p->next;
    }

    visitedL[i] = false;
}

int main()
{
    ALGraph G = Create();
    VertexType * path = (VertexType *)malloc(sizeof(VertexType) * MaxVextexNum);
    int length;

    PrintSimplePath(G, 'a', 'd', path, -1);

    return 0;
}