#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

int main()
{
	BiTree T;
	T = CreatBiTreeByPre();
	SqStack S;
	SqQueue Q;

	PreRec(T);
	cout << endl;
	Pre(T, S);
	cout << endl;

	MidRec(T);
	cout << endl;
	Mid(T, S);
	cout << endl;

	PosRec(T);
	cout << endl;
	Pos(T, S);
	cout << endl;

	Hir(T, Q);
	cout << endl;

	return 0;
}