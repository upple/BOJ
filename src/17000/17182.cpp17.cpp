#include <bits/stdc++.h>
using namespace std;

int arr[10][10];
int dp[10][1<<10];
int n, k;
int solve(int p, int h)
{
    if(dp[p][h]) return dp[p][h];
    if(h==(1<<n)-1) return 0;

    dp[p][h]=1e9;
    for(int i=0; i<n; i++)
    {
        if(h & (1<<i)) continue;
        dp[p][h]=min(dp[p][h], arr[p][i]+solve(i, h|(1<<i)));
    }
    return dp[p][h];
}
int main()
{
    cin>>n>>k;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(arr[i][j]>arr[i][k]+arr[k][j])
                {
                    arr[i][j]=arr[i][k]+arr[k][j];
                }
            }
        }
    }
    cout<<solve(k, 1<<k);
}