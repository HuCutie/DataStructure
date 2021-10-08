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

int Partition(SeqList & L, int low, int high)
{
    ElemType pivot = L.data[low];

    while(low < high)
    {
        while(low < high && L.data[high] >= pivot)
        {
            high--;
        }
        L.data[low] = L.data[high];

        while(low < high && L.data[low] <= pivot)
        {
            low++;
        }
        L.data[high] = L.data[low];
    }

    L.data[low] = pivot;
    return low;
}

void Quick(SeqList L, int low, int high)
{
    if(low < high)
    {
        int pivitPos = Partition(L, low, high);

        Quick(L, low, pivitPos-1);
        Quick(L, pivitPos+1, high);
    }
}

void AdjustHeap(SeqList & L, int k, int len)
{
    L.data[0] = L.data[k];

    for(int i = 2*k; i <= len; i *= 2)
    {
        if(i < len && L.data[i] < L.data[i+1])
        {
            i++;
        }

        if(L.data[0] >= L.data[i])
        {
            break;
        }
        else
        {
            L.data[k] = L.data[i];
            k = i;
        }
    }

    L.data[k] = L.data[0];
}

void BuildHeap(SeqList & L, int len)
{
    for(int i = len / 2; i > 0; i--)
    {
        AdjustHeap(L, i, len);
    }
}

void Heap(SeqList & L)
{
    ElemType temp;

    BuildHeap(L, L.length-1);

    for(int i = L.length-1; i > 1; i--)
    {
        temp = L.data[1];
        L.data[1] = L.data[i];
        L.data[i] = temp;

        AdjustHeap(L, 1, i-1);
    }
}

ElemType * sup = (ElemType *)malloc(sizeof(ElemType) * 11);
void Merging(SeqList & L, int low, int mid, int high)
{
    int i, j, k;

    for(k = low; k <= high; k++)
    {
        sup[k] = L.data[k];
    }

    for(i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if(sup[i] <= sup[j])
        {
            L.data[k] = sup[i++];
        }
        else
        {
            L.data[k] = sup[j++];
        }
    }

    while(i <= mid)
    {
        L.data[k++] = sup[i++];
    }
    while(j <= high)
    {
        L.data[k++] = sup[j++];
    }
}

void Merge(SeqList & L, int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        Merge(L, low, mid);
        Merge(L, mid+1, high);

        Merging(L, low, mid, high);
    }
}

int main()
{
    SeqList L;

    Init(L, 10);
    Print(L);

    Merge(L, 0, 9);
    Print(L);

    return 0;
}