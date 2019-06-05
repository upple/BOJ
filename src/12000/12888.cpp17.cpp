#include <iostream>
using namespace std;
typedef long long ll;
ll dp[70];
ll solve(int h)
{
    if(h==0) return 1;
    if(h<0) return 0;
    if(dp[h]) return dp[h];
    dp[h]=1;
    for(int i=h-1; i--;)
    {
        dp[h]+=solve(i)<<1;
    }

    return dp[h];
}
int main()
{
    int h;
    cin>>h;

    cout<<solve(h);
}