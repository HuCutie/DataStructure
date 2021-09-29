#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\ThreadBiTree.cpp"

void PreT(ThreadBiTree T)
{
    ThreadNode * p = T;
    while(p != NULL)
    {
        cout << p->data << " ";
        cout << p->ltag << " " << p->rtag << endl;

        if(p->ltag == 0)
        {
            p = p->lchild;
        }
        else if(p->rtag == 0)
        {
            p = p->rchild;
        }
        else
        {
            while(p != NULL && p->rtag == 1)
            {
                p = p->rchild;
            }

            if(p != NULL)
            {
                p = p->rchild;
            }
        }
    }

    cout << endl;
}

ThreadNode * PosT(ThreadNode * p)
{
    ThreadNode * q;

    if (p->ltag == 0)
    {
        q = p->lchild;
    }
    else if (p->rtag == 0)
    {
        q = p->rchild;
    }
    else if(p->lchild == NULL)
    {
        q = NULL;
    }
    else
    {
        while(p->ltag == 1 && p->lchild != NULL)
        {
            p = p->lchild;
        }

        if(p->ltag == 0)
        {
            q = p->lchild;
        }
        else
        {
            q = NULL;
        }
    }

    return q;
}

int main()
{
    ThreadBiTree T = CreatThreadBiTreeByPre();
    ThreadNode * q;
    CreateInThread(T);

    cout << FirstNode(T)->data << endl;

    InOrder(T);
    PreT(T);
    q = PosT(T->rchild);
    cout << q->data << endl;

    return 0;
}