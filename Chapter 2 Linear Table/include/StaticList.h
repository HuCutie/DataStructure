#include <iostream>

using namespace std;

#define MaxSize 50
#define ElemType int

typedef struct
{
    ElemType data;
    int next;
}StaticList[MaxSize];
