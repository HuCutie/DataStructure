#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 3 Stack and Queue\lib\Stack.cpp"

bool Push(SharedStack & S, int index, ElemType x)
{
    if(index < 0 || index > 1)
    {
        cout << "Wrong stack number." << endl;
        return false;
    }
    if(S.top[1] - S.top[0] == 1)
    {
        cout << "Stack is full." << endl;
        return false;
    }

    switch (index)
    {
    case 0:
        S.data[++S.top[0]] = x;
        return true;
        break;
    case 1:
        S.data[--S.top[1]] = x;
        return true;
        break;
    }
    return false;
}

bool Pop(SharedStack & S, int index, ElemType & x)
{
    if(index < 0 || index > 1)
    {
        cout << "Wrong stack number." << endl;
        return false;
    }
    if(S.top[1] == -1 || S.top[1] == MaxSize)
    {
        cout << "Stack is empty." << endl;
        return false;
    }

    switch(index)
    {
        case 0:
            if(S.top[0] > -1)
            {
                x = S.data[S.top[0]--];
                return true;
            }
            break;
        case 1:
            if(S.top[1] < MaxSize)
            {
                x = S.data[S.top[1]++];
                return true;
            }
            break;
    }
    return false;
}

int main()
{
    SharedStack S;
    InitSharedStack(S);
    ElemType x;

    Pop(S, 0, x);
    Pop(S, 1, x);

    for(int i = 0; i < MaxSize / 2; i++)
    {
        Push(S, 0, i+1);
        Push(S, 1, 50-i);
    }
    Push(S, 0, 26);
    Push(S, 1, 26);
    return 0;
}