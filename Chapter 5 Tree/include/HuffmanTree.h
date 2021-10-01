#include <iostream>
#include <string.h>

using namespace std;

#define ElemeType int

typedef struct
{
    ElemeType weight;
    int parent, lchild, rchild;
}HNode, * HTree;