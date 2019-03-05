#include <bits/stdc++.h>
using namespace std;

bool v[1001], dp[1001];
bool solve(int n)
{
    if(n<0) return 1;
    if(n<=1) return !n;
    if(v[n]) return dp[n];
    v[n]=1;
    if(!solve(n-1) || !solve(n-3) || !solve(n-4)) return dp[n]=1;
    return dp[n]=0;
}
int main()
{
    int n;
    cin>>n;
    cout<<(solve(n)?"SK":"CY");
}