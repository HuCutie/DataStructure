#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 6 Graph\include\MGraph.h"
#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 6 Graph\lib\StackAndQueue.cpp"

void InitGraph(MGraph & G)
{
    G.ArcNum = 0;

    cout << "Input the number of vertices: ";
    cin >> G.VexNum;

    cout << "Input each vertex: " << endl;
    for(int i = 0; i < G.VexNum; i++)
    {
        cin >> G.Vex[i];
    }

    for(int i = 0; i < G.VexNum; i++)
    {
        for(int j = 0; j < G.VexNum; j++)
        {
            G.edge[i][j] = 0;
        }
    }
}

void InitNet(MGraph & G)
{
    G.ArcNum = 0;

    cout << "Input the number of vertices: ";
    cin >> G.VexNum;

    cout << "Input each vertex: " << endl;
    for(int i = 0; i < G.VexNum; i++)
    {
        cin >> G.Vex[i];
    }

    for(int i = 0; i < G.VexNum; i++)
    {
        for(int j = 0; j < G.VexNum; j++)
        {
            //G.edge[i][j] = INT32_MAX;
            G.edge[i][j] = 0;
        }
    }
}

MGraph CreateDG()
{
    MGraph G;
    InitGraph(G);
    
    for(int i = 0; i < G.VexNum; i++)
    {
        for(int j = 0; j < G.VexNum; j++)
        {
            cout << "Enter 0 or 1 to distinguish whether there is an edge between " << G.Vex[i] << " and " << G.Vex[j] << " : ";
            cin >> G.edge[i][j];

            if(G.edge[i][j] == 1)
            {
                G.ArcNum++;
            }
        }
    }
    cout << "Directed graph G created completed." << endl;

    return G;
}

MGraph CreateUDG()
{
    MGraph G;
    InitGraph(G);
    
    for(int i = 0; i < G.VexNum; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << "Enter 0 or 1 to distinguish whether there is an edge between " << G.Vex[i] << " and " << G.Vex[j] << " : ";
            cin >> G.edge[i][j];
            G.edge[j][i] = G.edge[i][j];

            if(G.edge[i][j] == 1)
            {
                G.ArcNum++;
            }
        }
    }
    cout << "Undirected graph G created completed." << endl;

    return G;
}

MGraph CreateNet()
{
    MGraph G;
    EdgeType temp;
    InitNet(G);
    
    for(int i = 0; i < G.VexNum; i++)
    {
        for(int j = 0; j < G.VexNum; j++)
        {
            cout << "Input weight between " << G.Vex[i] << " and " << G.Vex[j] << " (-1 for no connection) : ";
            cin >> temp;
            if(temp == -1)
            {
                continue;
            }
            else
            {
                G.edge[i][j] = temp;
                G.VexNum++;
            }
        }
    }
    cout << "Net G created completed." << endl;

    return G;
}

void Print(MGraph G)
{
    for(int i = 0; i < G.VexNum; i++)
    {
        for(int j = 0; j < G.VexNum; j++)
        {
            if(G.edge[i][j] == 0)
            {
                cout << " inf ";
            }
            else
            {
                printf("%2d ", G.edge[i][j]);
            }
        }
        cout << endl;
    }
}

int GetIndex(MGraph G, VertexType x)
{
    int i;

    for(i = 0; i < G.VexNum; i++)
    {
        if(G.Vex[i] == x)
        {
            return i;
        }
    }

    return -1;
}

bool Adjacent(MGraph G, VertexType a, VertexType b)
{
    int i, j;

    i = GetIndex(G, a);
    j = GetIndex(G, b);

    if(i == -1 || j == -1)
    {
        cout << "Wrong vertex." << endl;
        return -1;
    }

    if(G.edge[i][j] != 0 && G.edge[j][i] != 0)
    {
        cout << a << " and " << b << " are both connectd." << endl;
        return true;
    }
    else if(G.edge[i][j] != 0 && G.edge[j][i] == 0)
    {
        cout << a << " to " << b << " is connectd." << endl;
        return true;
    }
    else if(G.edge[i][j] != 0 && G.edge[j][i] == 0)
    {
        cout << b << " to " << a << " is connectd." << endl;
        return true;
    }
    else
    {
        cout << "Not connectd." << endl;
        return false;
    }
}

void Neighbors(MGraph G, VertexType x)
{
    int i;
    i = GetIndex(G, x);

    for(int j = 0; j < G.VexNum; j++)
    {
        if(G.edge[i][j] != 0)
        {
            cout << G.Vex[i] << "->" << G.Vex[j] << endl;
        }
        if(G.edge[j][i] != 0)
        {
            cout << G.Vex[j] << "->" << G.Vex[i] << endl;
        }
    }
}

void InsertVertex(MGraph & G, VertexType x)
{
    int i;

    i = GetIndex(G, x);
    if(i != -1)
    {
        cout << "The vertex is already in the graph." << endl;
        return ;
    }

    G.VexNum++;
    G.Vex[G.VexNum-1] = x;


    for(int j = 0; j < G.VexNum; j++)
    {
        cout << "Input weight between " << x << " and " << G.Vex[j] << " (0 for no connection) : ";
        cin >> G.edge[G.VexNum-1][j];
        if(G.edge[G.VexNum-1][j] != 0)
        {
            G.ArcNum++;
        }

        cout << "Input weight between " << G.Vex[j] << " and " << x << " (0 for no connection) : ";
        cin >> G.edge[j][G.VexNum-1];
        if(G.edge[j][G.VexNum-1] != 0)
        {
            G.ArcNum++;
        }
    }
}

void DeleteVertex(MGraph & G, VertexType x)
{
    int i;

    i = GetIndex(G, x);
    if(i == -1)
    {
        cout << "The vertex is not in the graph." << endl;
        return ;
    }
    
    for(int j = i + 1; j < G.VexNum; j++)
    {
        G.edge[i-1][j] = G.edge[i][j];
        if(G.edge[i-1][j] != 0)
        {
            G.ArcNum--;
        }

        G.edge[j][i-1] = G.edge[j][i];
        if(G.edge[j][i-1] != 0)
        {
            G.ArcNum--;
        }
    }

    G.VexNum--;
    G.ArcNum++;
}

void AddEdge(MGraph & G, VertexType a, VertexType b)
{
    int i, j;
    EdgeType temp;

    i = GetIndex(G, a);
    j = GetIndex(G, b);

    if(i == -1 || j == -1)
    {
        cout << "The vertex is not in the graph." << endl;
        return ;
    }

    if(G.edge[i][j] == 0)
    {
        cout << "Input the weight between" << a << " and " << b <<" : ";
        cin >> temp;
        G.edge[i][j] = temp;

        G.ArcNum++;
    }
    else
    {
        cout << "The edge has alreay exists." << endl;
    }
}

void RemoveEdge(MGraph & G, VertexType a, VertexType b)
{
    int i, j;

    i = GetIndex(G, a);
    j = GetIndex(G, b);

    if(i == -1 || j == -1)
    {
        cout << "The vertex is not in the graph." << endl;
        return ;
    }

    if(G.edge[i][j] != 0)
    {
        G.edge[i][j] = 0;

        G.ArcNum--;
    }
    else
    {
        cout << "The edge does not exist." << endl;
    }
}

int FirstNeighbor(MGraph G, VertexType x)
{
    int i;

    i = GetIndex(G, x);

    if(i == -1)
    {
        cout << "The vertex is not in the graph." << endl;
        return -1;
    }

    for(int j = i; j < G.VexNum; j++)
    {
        if(G.edge[i][j] != 0)
        {
            return j;
        }
    }

    return -1;
}

int NextNeighbor(MGraph G, VertexType a, VertexType b)
{
    int i, j;

    i = GetIndex(G, a);
    j = GetIndex(G, b);

    if(i == -1 || j == -1)
    {
        cout << "The vertex is not in the graph." << endl;
        return -1;
    }

    for(int k = j+1; k < G.VexNum; k++)
    {
        if(G.edge[i][k] != 0)
        {
            return k;
        }
    }

    return -1;
}

EdgeType GetEdgeValue(MGraph G, VertexType a, VertexType b)
{
    int i, j;

    i = GetIndex(G, a);
    j = GetIndex(G, b);

    if(i == -1 || j == -1)
    {
        cout << "The vertex is not in the graph." << endl;
        return -1;
    }

    if(G.edge[i][j] == 0)
    {
        cout << "There is no connection between " << a << " and " << b << "." << endl;
        return -1;
    }
    else
    {
        return G.edge[i][j];
    }
}

void SetEdgeValue(MGraph & G, VertexType a, VertexType b)
{
    int i, j;
    EdgeType temp;

    i = GetIndex(G, a);
    j = GetIndex(G, b);

    if(i == -1 || j == -1)
    {
        cout << "The vertex is not in the graph." << endl;
        return ;
    }

    if(G.edge[i][j] == 0)
    {
        cout << "There is no connection between " << a << " and " << b << "." << endl;
        return ;
    }
    else
    {
        cout << "Input the weight value between " << a << " and " << b << " : ";
        cin >> temp;
        G.edge[i][j] = temp;
    }
}

void Multiply(MGraph & G, int n)
{
    int i, j;
    EdgeType temp;

    for(int count = 0; count < n; count++)
    {
        for(i = 0; i < G.VexNum; i++)
        {
            temp = 0;
            for(j = 0; j < G.VexNum; j++)
            {
                temp += G.edge[i][j] * G.edge[j][i]; 
            }
            G.edge[i][j] = temp;
        }
    }
}

bool visited[MaxVertexNum];
void BFS(MGraph G, SqQueue & Q, int i)
{
    EnQueue(Q, i);
    visited[i] = true;

    while(!QueueEmpty(Q))
    {
        DeQueue(Q, i);
        cout << G.Vex[i] << " ";

        for(int j = FirstNeighbor(G, G.Vex[i]); j >= 0; j = NextNeighbor(G, G.Vex[i], G.Vex[j]))
        {
            if(!visited[j])
            {
                cout << G.Vex[j] << " ";
                visited[j] = true;

                EnQueue(Q, j);
            }
        }
    }
}

void BFSTravel(MGraph G)
{
    SqQueue Q;

    for(int i = 0; i < G.VexNum; i++)
    {
        visited[i] = false;
    }

    InitQueue(Q);

    for(int i = 0; i < G.VexNum; i++)
    {
        if(!visited[i])
        {
            BFS(G, Q, i);
        }
    }
}

void MinDistanceByBFS(MGraph G, SqQueue Q, int * dis, int i)
{
    dis = (int *)malloc(sizeof(int) * G.VexNum);

    for(int j = 0; j < G.VexNum; i++)
    {
        visited[i] = false;
        dis[i] = INT32_MAX;
    }

    visited[i] = true;
    dis[i] = 0;

    EnQueue(Q, i);
    while(!QueueEmpty(Q))
    {
        DeQueue(Q, i);

        for(int j = FirstNeighbor(G, G.Vex[i]); j >= 0; j = NextNeighbor(G, G.Vex[i], G.Vex[j]))
        {
            if(!visited[j])
            {
                visited[j] = true;
                dis[j] = dis[i]+1;
                EnQueue(Q, j);
            }
        }
    }
}

void DFS(MGraph G, int i)
{
    cout << G.Vex[i] << " ";
    visited[i] = true;

    for (int j = FirstNeighbor(G, G.Vex[i]); j >= 0; j = NextNeighbor(G, G.Vex[i], G.Vex[j]))
    {
        if (!visited[j])
        {
            DFS(G, j);
        }
    }
}

void DFSTravle(MGraph G)
{
    for(int i = 0; i < G.VexNum; i++)
    {
        visited[i] = false;
    }

    for(int i = 0; i < G.VexNum; i++)
    {
        if(!visited[i])
        {
            DFS(G, i);
        }
    }
}

void DFS(MGraph G, SqStack S, int index)
{
    int temp;
    InitStack(S);
    
    for(int i = 0; i < G.VexNum; i++)
    {
        visited[i] = false;
    }

    Push(S, index);
    visited[index] = true;

    while(!StackEmpty(S))
    {
        Pop(S, temp);
        cout << G.Vex[temp] << " ";

        for (int j = FirstNeighbor(G, G.Vex[index]); j >= 0; j = NextNeighbor(G, G.Vex[index], G.Vex[j]))
        {
            if(!visited[j])
            {
                Push(S, j);
                visited[j] = true;
            }
        }
    }
}