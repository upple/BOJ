#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10];

int solve(int p, int c)
{
    if(p==n) return (c==4?0:-10000000);
    if(c==4) return -10000000;
    int ret=1, _max=-10000000;

    for(int i=p; i<n; i++)
    {
        ret*=arr[i];
        _max=max(_max, ret+solve(i+1, c+1));
    }

    return _max;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<solve(0, 0);
}