#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\include\HuffmanTree.h"

void Select(HTree T, int end, int * s1, int * s2)
{
    int min1, min2;
    int i = 1;

    while(T[i].parent != 0 && i <= end)
    {
        i++;
    }

    min1 = T[i].weight;
    *s1 = i;

    i++;
    while(T[i].parent != 0 && i <= end)
    {
        i++;
    }

    if(T[i].weight < min1)
    {
        min2 = min1;
        *s2 = *s1;
        min1 = T[i].weight;
        *s1 = i;
    }
    else
    {
        min2 = T[i].weight;
        *s2 = i;
    }

    for(int j = i+1; j <= end; j++)
    {
        if(T[j].parent != 0)
        {
            continue;
        }

        if(T[j].weight < min1)
        {
            min2 = min1;
            min1 = T[j].weight;
            *s2 = *s1;
            *s1 = j;
        }
        else if(T[j].weight >= min1 && T[j].weight <= min2)
        {
            min2 = T[j].weight;
            *s2 = j;
        }
    }
}

void Create(HTree & T, ElemeType * weight, int n)
{
    if(n <= 1)
    {
        return ;
    }

    int num = 2 * n - 1;
    T = (HNode *)malloc(sizeof(HNode) * (num+1));

    HNode * p = T;

    for(int i = 1; i <= n; i++)
    {
        (p+i)->weight = *(weight+i-1);
        (p+i)->parent = 0;
        (p+i)->lchild = 0;
        (p+i)->rchild = 0;
    }

    for(int i = n+1; i <= num; i++)
    {
        (p+i)->weight = 0;
        (p+i)->parent = 0;
        (p+i)->lchild = 0;
        (p+i)->rchild = 0;
    }

    for(int i = n+1; i <= num; i++)
    {
        int s1, s2;
        Select(T, i - 1, &s1, &s2);

        T[s1].parent = 1;
        T[s2].parent = 1;

        T[i].lchild = s1;
        T[i].rchild = s2;

        T[i].weight = T[s1].weight + T[s2].weight;
    }
}

void Encode(HTree T, char *** code, int n)
{
    *code = (char **)malloc(sizeof(char *) * (n+1));
    char * temp = (char *)malloc(sizeof(char) * n);

    temp[n-1] = '\0';

    for(int i = 1; i <= n; i++)
    {
        int start = n-1;
        int count = i;
        int j = T[i].parent;

        while(j != 0)
        {
            if(T[j].lchild == 0)
            {
                temp[--start] = '0';
            }
            else
            {
                temp[--start] = '1';
            }

            count = j;
            j = T[j].parent;
        }

        *code[i] = (char *)malloc(sizeof(char) * (n-start));
        strcpy(*code[i], &temp[start]);
    }

    free(temp);
}

void Print(char ** code, ElemeType * weight, int n)
{
    cout << "Huffman code: " << endl;

    for(int i = 1; i <= n; i++)
    {
        cout << weight[i-1] << " : " << code[i] << endl;
    }
}

int main()
{
    HTree T;
    char ** code;
    int weight[5] = {2, 8, 7, 6, 5};
    int n = 5;

    Create(T, weight, n);
    Encode(T, &code, n);
    Print(code, weight, n);

    return 0;
}