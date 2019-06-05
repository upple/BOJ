#include <iostream>
#include <algorithm>
using namespace std;

int n, l, r, x;
int arr[15];

int solve(int p, int sum, int _min, int _max)
{
    if(p==n) return (sum>=l && _max-_min>=x);

    int ret=0;
    int lmin=min(_min, arr[p]);
    int lmax=max(_max, arr[p]);
    if(sum+arr[p]<=r) ret+=solve(p+1, sum+arr[p], lmin, lmax);
    ret+=solve(p+1, sum, _min, _max);

    return ret;
}
int main()
{
    cin>>n>>l>>r>>x;

    for(int i=0;i<n; i++)
        cin>>arr[i];

    cout<<solve(0, 0, 1e9, 0);

}