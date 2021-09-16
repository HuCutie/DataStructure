#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Liner Table\lib\SqList.cpp"

int main()
{
    SqList L;

    ListInit(L, 10);
    ListPrint(L);

    ListInsert(L, 3, 999);
    ListPrint(L);

    ElemType e;
    ListDelete(L, 3, e);
    cout << e << endl;
    ListPrint(L);

    cout << LocateElem(L, L.data[2]) << endl;

    return 0;
}