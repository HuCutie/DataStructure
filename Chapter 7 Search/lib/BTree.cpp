#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 7 Search\include\BTree.h"

void InitBTree(BTree & T)
{
    T = (BNode *)malloc(sizeof(BNode));

    T->isLeaf = true;
    T->num = 0;
}

bool BNodeFull(BTree T)
{
    if(T->num < level)
    {
        return false;
    }

    return true;
}

void Split(BTree & T)
{
    BNode * p1 = T;
    BNode * p2;
    BNode * p;

    InitBTree(p2);

    int num = p1->num;
    int split = num / 2;
    
    
}

void Insert(BTree & T, ElemType x)
{
    BNode * p = T;

    if(BNodeFull(p))
    {
        Split(p);
        Insert(p, x);
        return ;
    }

    if(p->isLeaf && !BNodeFull(p))
    {
        if(x > p->data[p->num - 1])
        {
            p->num++;
            p->data[p->num-1] = x;
        }
        else
        {
            for(int i = 0; i < level-1; i++)
            {
                if(x < p->data[i])
                {
                    ElemType temp = p->data[i];
                    p->data[i] = x;
                    p->num++;

                    for(int j = i+1; j < p->num; j++)
                    {
                        x = p->data[j];
                        p->data[j] = temp;
                        temp = x;
                    }

                    break;  
                }
            }
        }

        return ;
    }

    if(!p->isLeaf)
    {
        for(int i = 0; i < p->num; i++)
        {
            if(x < p->data[i])
            {
                Insert(p->child[i], x);
                return ;
            }
        }

        Insert(p->child[p->num], x);
    }
}