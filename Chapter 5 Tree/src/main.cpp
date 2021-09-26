#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

int main()
{
	BiTree T;
	T = CreatBiTreeByPre();
	SqStack S;
	SqQueue Q;

	cout << "Ç°ÐòµÝ¹é:";
	PreRec(T);
	cout << endl;
	cout << "Ç°Ðò·ÇµÝ¹é:";
	Pre(T, S);
	cout << endl;

	cout << "ÖÐÐòµÝ¹é:";
	MidRec(T);
	cout << endl;
	cout << "ÖÐÐò·ÇµÝ¹é:";
	Mid(T, S);
	cout << endl;

	cout << "ºóÐøµÝ¹é:";
	PosRec(T);
	cout << endl;
	cout << "ºóÐò·ÇµÝ¹é:";
	Pos(T, S);
	cout << endl;

	cout << "²ã´Î±éÀú:";
	Hir(T, Q);
	cout << endl;

	return 0;
}