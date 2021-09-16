#include <iostream>

using namespace std;

#define InitSize 100

#define ElemType int

struct SeqList
{
    ElemType * data;
    int MaxSize, length;
};