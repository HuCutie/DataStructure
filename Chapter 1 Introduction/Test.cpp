#include <iostream>

using namespace std;

int main()
{
    long long sum = 0;
    int n, temp = 1;
    cin>>n;
    for (int i = n; i > 0; i--)
    {
        sum += temp * i;
        temp++;
    }
    cout<<sum<<endl;
    return 0;
}