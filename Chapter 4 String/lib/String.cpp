#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 4 String\include\String.h"

int BF(SString S, SString T)
{
    int i = 1, j = 1;
    while(i <= S.length && j <= T.length)
    {
        if(S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }

    if(j > T.length)
    {
        return i - T.length;
    }

    return -1;
}

void GetNext(SString T, int * next)
{
    int i = 1, j = 0;
    next[1] = 0;

    while(i < T.length)
    {
        if(j == 0 || T.ch[i] == T.ch[j])
        {
            i++;
            j++;

            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

void GetNextVal(SString T, int * nextval)
{
    int i = 1, j = 0;
    nextval[1] = 0;

    while(i < T.length)
    {
        if(j == 0 || T.ch[i] == T.ch[j])
        {
            i++;
            j++;

            if(T.ch[i] != T.ch[j])
            {
                nextval[i] = j;
            }
            else
            {
                nextval[i] = nextval[j];
            }
        }
        else
        {
            j = nextval[j];
        }
    }
}

int KMP(SString S, SString T, int * next)
{
    int i = 1, j = 1;
    while(i <= S.length && j <= T.length)
    {
        if(j == 0 || S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if(j > T.length)
    {
        return i - T.length;
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    int * next = (int *)malloc(sizeof(int) * n+1);

    SString T;

    for(int i = 1; i <= n; i++)
    {
        cin >> T.ch[i];
        T.length++;
    }

    for(int i = 1; i <= n; i++)
    {
        next[i] = 0;
    }

    GetNext(T, next);

    for(int i = 1; i <= n; i++)
    {
        cout << next[i];
    }
    cout << endl;

    return 0;
}