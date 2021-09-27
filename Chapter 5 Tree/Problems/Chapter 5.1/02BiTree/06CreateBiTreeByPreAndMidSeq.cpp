#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

BiTree CreateBiTreeByPreAndMidSeq(ElemType * pre, ElemType * mid, int s1, int e1, int s2, int e2)
{
    int i;
    BiTNode * T = (BiTNode *)malloc(sizeof(BiTNode));
    ElemType root = pre[s1];

    for(i = s2; i < e2; i++)
    {
        if(mid[i] == root)
        {
            break;
        }
    }
    int llen = i - s2;
    int rlen = e2 - i;

    T->data = root;

    if(llen > 0)
    {
        T->lchild = CreateBiTreeByPreAndMidSeq(pre, mid, s1+1, s1+llen, s2, s2+llen-1);
    }
    else
    {
        T->lchild = NULL;
    }

    if(rlen > 0)
    {
        T->rchild = CreateBiTreeByPreAndMidSeq(pre, mid, e1-rlen+1, e1, e2-rlen+1, e2);
    }
    else
    {
        T->rchild = NULL;
    }

    return T;
}

int main()
{
    BiTree T;
    ElemType pre[] = {'a', 'b', 'c'};
    ElemType mid[] = {'b', 'a', 'c'};

	T = CreateBiTreeByPreAndMidSeq(pre, mid, 0, 2, 0, 2);

	PreRec(T);
	cout << endl;
    return 0;
}