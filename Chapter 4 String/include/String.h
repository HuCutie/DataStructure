#include <iostream>

using namespace std;

#define MaxSize 255

typedef struct
{
    char ch[MaxSize];
    int length = 0;
}SString;

typedef struct
{
    char * ch;
    int length = 0;
}HString;

