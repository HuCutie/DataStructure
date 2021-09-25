#include "Stack.cpp"
#include "Queue.cpp"

bool BracketMatching(SqStack & S, ElemType * seq)
{
    ElemType x;
    for(int i = 0; i < 6; i++)
    {
        if(seq[i] == 1 || seq[i] == 2 || seq[i] == 3)
        {
            Push(S, seq[i]);
        }
        else if(seq[i] == 0)
        {
            GetTop(S, x);
            if(StackEmpty(S) || x != 1)
            {
                return false;
            }
            else
            {
                Pop(S, x);
            }
        }
        else if(seq[i] == 9)
        {
            GetTop(S, x);
            if(StackEmpty(S) || x != 2)
            {
                return false;
            }
            else
            {
                Pop(S, x);
            }
        }
        else if(seq[i] == 8)
        {
            GetTop(S, x);
            if(StackEmpty(S) || x != 3)
            {
                return false;
            }
            else
            {
                Pop(S, x);
            }
        }
    }

    if(StackEmpty(S))
    {
        return true;
    }

    return false;
}



int main()
{
    int * seq = (int *)malloc(sizeof(ElemType) * 6);
    SqStack S;

    InitStack(S);

    for(int i = 0; i < 6; i++)
    {
        cin >> seq[i];
    }

    cout << BracketMatching(S, seq) << endl;
    return 0;
}