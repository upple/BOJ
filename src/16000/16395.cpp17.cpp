#include <bits/stdc++.h>
using namespace std;

int dp[31][31];

int solve(int n, int k)
{
    if(k==0 || n==k) return 1;
    if(dp[n][k]) return dp[n][k];
    return dp[n][k]=solve(n-1, k)+solve(n-1, k-1);
}
int main()
{
    int n, k;
    cin>>n>>k;
    n--, k--;
    if(k>n-k) k=n-k;
    cout<<solve(n, k);
}