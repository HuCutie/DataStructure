#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

int main()
{
	BiTree T;
	T = CreatBiTreeByPre();
	SqStack S;
	SqQueue Q;

	cout << "ǰ��ݹ�:";
	PreRec(T);
	cout << endl;
	cout << "ǰ��ǵݹ�:";
	Pre(T, S);
	cout << endl;

	cout << "����ݹ�:";
	MidRec(T);
	cout << endl;
	cout << "����ǵݹ�:";
	Mid(T, S);
	cout << endl;

	cout << "�����ݹ�:";
	PosRec(T);
	cout << endl;
	cout << "����ǵݹ�:";
	Pos(T, S);
	cout << endl;

	cout << "��α���:";
	Hir(T, Q);
	cout << endl;

	return 0;
}