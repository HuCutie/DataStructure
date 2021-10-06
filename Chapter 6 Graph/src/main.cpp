#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 6 Graph\lib\MGraph.cpp"

int main(int argc, char *argv[])
{
	MGraph G;

	G = CreateUDG();
	Print(G);

	BFSTravel(G);

	return 0;
}