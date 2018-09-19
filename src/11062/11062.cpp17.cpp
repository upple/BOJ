#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > dp[2];
int arr[1000];

int solve(int c, int s, int e)
{
    if(dp[c][s][e] || s==e) return dp[c][s][e];
    if(c) dp[c][s][e]=max(arr[s]+solve(!c, s+1, e), arr[e]+solve(!c, s, e-1));
    else dp[c][s][e]=min(solve(!c, s+1, e), solve(!c, s, e-1));
    return dp[c][s][e];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        dp[0].assign(n, vector<int>(n, 0));
        dp[1].assign(n, vector<int>(n, 0));
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            dp[1][i][i]=arr[i];
        }

        cout<<solve(1, 0, n-1)<<"\n";
    }
}