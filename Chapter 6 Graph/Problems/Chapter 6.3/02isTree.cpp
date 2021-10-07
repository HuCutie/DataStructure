#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 6 Graph\lib\MGraph.cpp"

bool isTree(MGraph G)
{
    BFSTravel(G);
    cout << endl;

    for(int i = 0; i < G.VexNum; i++)
    {
        if(visited[i] == false)
        {
            return false;
        }
    }

    if(G.VexNum-1 != G.ArcNum)
    {
        return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
	MGraph G;

    G = CreateUDG();
    Print(G);

    cout << isTree(G) << endl;

	return 0;
}