#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 6 Graph\lib\ALGraph.cpp"

void DFSNotByRec(ALGraph G, SqStack S, int index)
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

int main(int argc, char *argv[])
{
	ALGraph G;
    SqStack S;

    InitStack(S);
	G = Create();

	DFSTravel(G);
    cout << endl;
    DFS(G, S, 0);

	return 0;
}