#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\SqList.cpp"
#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 2 Linear Table\lib\LinkList.cpp"

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

    LinkList LL;
    LL = LinkHInsert(5);
    LinkPrint(LL);
    LL = LinkTInsert(5);
    LinkPrint(LL);

    LNode * p = GetElemByNum(LL, 1);
    cout << "No.1 " << p->data << endl;
    p = LinkInsert(LL, 2, 999);
    cout << p->next << endl;
    LinkPrint(LL);
    
    LinkDelete(LL, 2);
    LinkPrint(LL);

    cout << GetLinkLength(LL) << endl;
    return 0;
}