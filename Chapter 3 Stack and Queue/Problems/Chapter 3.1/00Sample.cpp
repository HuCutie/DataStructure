#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 3 Stack and Queue\lib\Stack.cpp"

int main()
{
    SqStack S;
    InitStack(S);

    for(int i = 0; i < 5; i++)
    {
        Push(S, i+1);
    }

    for(int i =0; i < 5; i++)
    {
        ElemType x;
        Pop(S, x);
        cout << x << "  ";
    }
    cout << endl;

    return 0;
}