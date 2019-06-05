#include <bits/stdc++.h>
using namespace std;

const long long LMT = 1000000000000000000LL;
int s=2;
long long dp[10000]={1, 7};

int solve(long long n)
{
    int it=lower_bound(dp, dp+s, n)-dp;
    return it;
}
int main()
{
    long long n;
    cin>>n;
    for(int i=2;;i++)
    {
        int k=i;
        dp[i]=i;
        while(k--)
        {
            dp[i]+=dp[i]+1;
        }

        dp[i]+=dp[i]+1;
        s++;
        if(dp[i]>=n) break;
    }
    
    cout<<solve(n)<<"\n";
}