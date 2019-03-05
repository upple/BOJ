#include <bits/stdc++.h>
using namespace std;

int dp[1000001];
bool v[1000001];
int n;
int solve(int x)
{
    if(x==n) return 0;
    if(v[x]) return dp[x];
    if(x>n) return 1e9;
    v[x]=true;
    return dp[x] = 1+min({solve(x+1), solve(x*2), solve(x*3)});
}
int main()
{
    cin>>n;
    cout<<solve(1);
}