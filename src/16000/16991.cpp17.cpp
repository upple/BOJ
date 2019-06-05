#include <bits/stdc++.h>
using namespace std;

double dp[16][1<<16];
double arr[16][2];
int n;

inline double dist(double *a, double *b)
{
    return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}

double solve(int p, int h)
{
    if(h==(1<<n)-1) return dist(arr[p], arr[0]);
    if(dp[p][h]) return dp[p][h];

    dp[p][h]=1e9;
    for(int i=0; i<n; i++)
    {
        if(h&(1<<i)) continue;
        dp[p][h]=min(dp[p][h], dist(arr[i], arr[p])+solve(i, h+(1<<i)));
    }

    return dp[p][h];
}
int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>arr[i][0]>>arr[i][1];

    cout.precision(11);
    cout<<solve(0, 1);
}