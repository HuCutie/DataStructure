#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 6 Graph\lib\MGraph.cpp"

int main(int argc, char *argv[])
{
	MGraph G;
	SqStack S;

	G = CreateUDG();
	Print(G);

	DFSTravle(G);
	cout << endl;

	BFSTravel(G);
	cout << endl;

	DFS(G, S, 0);

	return 0;
}