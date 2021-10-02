#include <iostream>

using namespace std;

#define ElemType int

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
