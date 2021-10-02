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

int DivideSeq(SeqList L, Block & block)
{
    int num;
    int per;

    cout << "Input the number of blocks: ";
    cin >> num;
    block  = (BlockNode *)malloc(sizeof(BlockNode) * num);
    per = L.length % num == 0 ? L.length / num : L.length / num + 1;

    for(int i = 0; i < num; i++)
    {
        block[i].start = i * per;
        block[i].end = (i+1) * per - 1;
    }
    if(per * num > L.length)
    {
        block[num-1].end = L.length-1;
    }

    return num;
}

int BlockSearch(SeqList L, ElemType x)
{
    Block block;
    int i = 0;
    int index;
    ElemType startValue;

    int num = DivideSeq(L, block);

    while(i < num && L.data[block[i].end] < x)
    {
        i++;
    }

    if(i >= num)
    {
        return -1;
    }

    startValue = block[i].start;
    for(index = block[i].start; i < block[i].end; index++)
    {
        if(L.data[index] == x)
        {
            return index;
        }
    }

    if(L.data[index] > L.data[block[i].end])
    {
        return -1;
    }

    return -1;
}