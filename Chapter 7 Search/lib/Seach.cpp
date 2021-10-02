#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 7 Search\include\Search.h"

int SeqSearch(SeqList L, ElemType key)
{
    int i;
    for(i = 0; i < L.length; i++)
    {
        if(L.data[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int BiSearch(SeqList L, ElemType key)
{
    int low = 0;
    int high = L.length - 1;
    int mid;

    while(low <= high)
    {
        mid = (high - low) / 2;

        if(L.data[mid] == key)
        {
            return mid;
        }
        else if(L.data[mid] < key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

