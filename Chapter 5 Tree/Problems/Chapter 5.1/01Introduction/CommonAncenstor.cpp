#include <iostream>

using namespace std;

int CommonAncestor(char * T, int i, int j)
{
    if(T[i] != '#' && T[j] != '#')
    {
        while (i != j)
        {
            if (i > j)
            {
                i /= 2;
            }
            else
            {
                j /= 2;
            }
        }
        cout << T[i] << endl;
        return i;
    }
    return -1;
}

int main()
{
    char * T;
    int size;

    cin >> size;
    T = (char *)malloc(sizeof(char) * (size + 1));

    for(int i = 1; i <= size; i++)
    {
        cin >> T[i];
    }

    int i, j;
    cin >> i >> j;
    cout << CommonAncestor(T, i, j);

    return 0;
}