#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\BiTree.cpp"

void Pre2Post(ElemType * pre, int s1, int e1, ElemType * post, int s2, int e2)
{
    int mid;

    if(e1 >= s1)
    {
        post[e2] = pre[s1];
        mid = (e1-s1)/2;
        Pre2Post(pre, s1+1, s1+mid, post, s2, s2+mid-1);
        Pre2Post(pre, s1+mid+1, e1, post, s2+mid, e2-1);
    }
}

int main()
{
    int n;

    cin >> n;

    ElemType * pre = (ElemType *)malloc(sizeof(ElemType) * n);
    ElemType * post = (ElemType *)malloc(sizeof(ElemType) * n);

    for(int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    for(int i = 0; i < n; i++)
    {
        cout << pre[i];
    }
    cout << endl;

    Pre2Post(pre, 0, n - 1, post, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        cout << post[i];
    }
    cout << endl;

    return 0;
}