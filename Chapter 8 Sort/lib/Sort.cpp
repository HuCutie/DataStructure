#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 8 Sort\include\Sort.h"

void Init(SeqList & L, int n)
{
    L.data = (ElemType *)malloc(sizeof(ElemType) * n);

    for(int i = 0; i < n; i++)
    {
        L.data[i] = n-i;
    }
    L.length = n;
}

void Print(SeqList L)
{
    for(int i = 0; i < L.length; i++)
    {
        printf("%2d ", L.data[i]);
    }
    cout << endl;
}

void Bubble(SeqList & L)
{
    ElemType temp;
    bool flag;

    for(int i = 0; i < L.length; i++)
    {
        flag = false;
        for(int j = i+1; j < L.length; j++)
        {
            if(L.data[i] > L.data[j])
            {
                temp = L.data[i];
                L.data[i] = L.data[j];
                L.data[j] = temp;

                flag = true;
            }
        }
        if(!flag)
        {
            return ;
        }
    }
}

void Insert(SeqList & L)
{
    ElemType guard;
    int i, j;

    for(i = 1; i < L.length; i++)
    {
        if(L.data[i] < L.data[i-1])
        {
            guard = L.data[i];
        }
        for(j = i-1; L.data[j] > guard && j >= 0; j--)
        {
            L.data[j+1] = L.data[j];
        }
        L.data[j+1] = guard;
    }
}

void BiInsert(SeqList & L)
{
    ElemType guard;
    int i, j;
    int low, high, mid;

    for(i = 1; i < L.length; i++)
    {
        guard = L.data[i];
        low = 0;
        high = i - 1;

        while(low <= high)
        {
            mid = (high - low) / 2;
            if(L.data[mid] > guard)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        for(j = i-1; j >= high+1; j--)
        {
            L.data[j+1] = L.data[j];
        }
        L.data[j+1] = guard;
    }
}

void Shell(SeqList & L)
{
    ElemType guard;
    int i, j;

    for(int delta = L.length/2; delta >= 1; delta /= 2)
    {
        for(i = delta; i < L.length; i++)
        {
            if(L.data[i] < L.data[i-delta])
            {
                guard = L.data[i];

                for(j = i-delta; j >= 0 && L.data[j] > guard; j -= delta)
                {
                    L.data[j+delta] = L.data[j];
                }

                L.data[j+delta] = guard;
            }            
        }
    }
}

void Select(SeqList & L)
{
    int min;
    ElemType temp;
    int i, j;

    for(i = 0; i < L.length; i++)
    {
        min = i;

        for(j = i+1; j < L.length; j++)
        {
            if(L.data[j] < L.data[min])
            {
                min = j;
            }
        }

        temp = L.data[i];
        L.data[i] = L.data[min];
        L.data[min] = temp;
    }
}

int MaxBit(SeqList L)
{
    int max = L.data[0];
    int d;
    int count;

    for(int i = 1; i < L.length; i++)
    {
        if(L.data[i] > max)
        {
            max = L.data[i];
        }
    }

    d = 10;
    count = 0;
    while(max != 0)
    {
        max /= d;
        count++;
    }

    return count;
}

void Radix(SeqList & L)
{
    int maxBit = MaxBit(L);

    ElemType * temp = (ElemType *)malloc(sizeof(ElemType) * L.length);

    int * count = (int *)malloc(sizeof(int) * 10);

    int i;
    int j;
    int k;

    int radix = 1;

    for(i = 0; i < maxBit; i++)
    {
        for(j = 0; j < 10; j++)
        {
            count[j] = 0;
        }

        for(j = 0; j < L.length; j++)
        {
            k = (L.data[j] / radix) % 10;
            count[k]++;
        }

        for(j = 1; j < 10; j++)
        {
            count[j] += count[j-1];
        }

        for(j = L.length-1; j >= 0; j--)
        {
            k = (L.data[j] / radix) % 10;
            temp[count[k]-1] = L.data[j];
            count[k]--;
        }

        for(j = 0; j < L.length; j++)
        {
            L.data[j] = temp[j];
        }

        radix *= 10;
    }

    free(count);
    free(temp);
}

int main()
{
    SeqList L;

    Init(L, 10);
    Print(L);

    Radix(L);
    Print(L);

    return 0;
}