#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 3 Stack and Queue\lib\Queue.cpp"

int main()
{
    SqQueue Q;
    ElemType x;
    InitQueue(Q);
    cout << QueueEmpty(Q) << endl;
    DeQueue(Q, x);
    EnQueue(Q, 999);

    DeQueue(Q, x);
    cout << x << endl;
    return 0;
}