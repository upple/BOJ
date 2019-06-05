#include <bits/stdc++.h>
using namespace std;

char arr[1002][1002];
int dp[1002][1002];
int n, m;
int sx, sy;
const int ERR=-1*(1e9);

int solve(int i, int j)
{
    if(!arr[i][j] || arr[i][j]=='#') return ERR;
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=(arr[i][j]=='C');
    int ret=max({solve(i+1, j+1), solve(i-1, j+1), solve(i, j+1)});
    if(ret==ERR) return dp[i][j]=(arr[i][j]=='O'?0:ERR);
    return dp[i][j]+=ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    memset(dp, -1, sizeof(dp));
    bool find=false;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i]+1;
        if(find) continue;
        for(int j=1; j<=m; j++)
        {
            if(arr[i][j]=='R')
            {
                sx=i, sy=j;
                arr[i][j]='.';
                break;
            }
        }
    }

    int ans=solve(sx, sy);
    cout<<(ans==ERR?-1:ans);
}