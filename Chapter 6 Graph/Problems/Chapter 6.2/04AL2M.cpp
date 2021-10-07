#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 6 Graph\lib\MGraph.cpp"
#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 6 Graph\lib\ALGraph.cpp"

void AL2M(ALGraph G, MGraph & M)
{
    ArcNode * p;

    for(int i = 0; i < G.VexNum; i++)
    {
        M.Vex[i] = G.vertices[i].data;

        p = G.vertices[i].first;
        while(p != NULL)
        {
            M.edge[i][p->adjvex] = 1;
            p = p->next;
        }
    }

    M.VexNum = G.VexNum;
    M.ArcNum = G.ArcNum;
}

int main(int argc, char *argv[])
{
	ALGraph G;
	MGraph M;

	G = Create();
	
	AL2M(G, M);
    Print(M);

    DFSTravle(M);
    cout << endl;

	return 0;
}