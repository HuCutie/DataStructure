#include <iostream>

using namespace std;

typedef unsigned long long ElemType;

typedef struct
{
    ElemType * data;
    int length;
} SeqList;

typedef struct
{
    int start;
    int end;
} BlockNode, * Block;
