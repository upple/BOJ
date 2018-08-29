#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;

int dp[3][100001]={{0, 1, 0, 1, }, {0, 0, 1, 1,}, {0, 0, 0, 1}};
bool v[3][100001];
int solve(int c, int x)
{
    if(x<=0) return 0;
    if(v[c][x]) return dp[c][x];
    v[c][x]=1;
    return dp[c][x]=(solve((c+2)%3, x-c-1)+solve((c+1)%3, x-c-1))%MOD;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0; i<3; i++)
        v[i][1]=v[i][2]=v[i][3]=1;

    while(t--)
    {
        int n, ans=0;
        cin>>n;
        for(int i=0; i<3; i++)
            ans=(ans+solve(i, n))%MOD;

        cout<<ans<<"\n";
    }
}