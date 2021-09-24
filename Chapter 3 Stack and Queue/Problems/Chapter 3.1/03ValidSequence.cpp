#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 3 Stack and Queue\lib\Stack.cpp"

bool ValidSequence(SqStack & S, int * seq)
{
    ElemType x;
    for(int i = 0; i < 8; i++)
    {
        if(seq[i] == 1)
        {
            Push(S, seq[i]);
        }
        else
        {
            GetTop(S, x);
            if(x != 1)
            {
                return false;
            }
            else
            {
                Pop(S, x);
            }
        }
    }
    
    if(S.top == -1)
    {
        return true;
    }
    return false;
}

int main()
{
    SqStack S;
    int * seq = (int *)malloc(sizeof(int) * 8);
    InitStack(S);

    for(int i = 0; i < 8; i++)
    {
        cin >> seq[i];
    }

    cout << ValidSequence(S, seq) << endl;

    return 0;
}