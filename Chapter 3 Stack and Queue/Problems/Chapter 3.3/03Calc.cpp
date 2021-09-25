#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 3 Stack and Queue\lib\Stack.cpp"

double Calc(int n, double x)
{
    if(n == 0)
    {
        return 1;
    }
    if(n == 1)
    {
        return 2 * x;
    }
    return 2 * x * Calc(n - 1, x) - 2 * (n - 1) * Calc(n - 2, x);
}

double Calc(SqStack & S, int n, double x)
{
    double v1 = 1;
    double v2 = 2 * x;
    ElemType t;

    if(n == 0)
    {
        return v1;
    }

    for(int i = n; i >= 2; i--)
    {
        Push(S, i);
    }

    while(!StackEmpty(S))
    {
        S.data[S.top] = 2*x*v2 - 2*(n-1)*v1;
        v1 = v2;
        GetTop(S, t);
        v2 = t;
        Pop(S, t);
    }

    return v2;
}

int main()
{
    SqStack S;
    int n;
    double x;

    InitStack(S);
    cin >> n >> x;

    cout << Calc(n, x) << endl;
    cout << Calc(S, n, x) << endl;
    return 0;
}