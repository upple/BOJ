#include <bits/stdc++.h>
using namespace std;

vector<int> adj[30001];
int p[20][30001], d[30001];

void dfs(int cur, int priv)
{
    for(int next : adj[cur])
    {
        if(next==priv) continue;
        d[next]=d[cur]+1;
        p[0][next]=cur;
        dfs(next, cur);
    }
}

int lca(int a, int b)
{
    if(d[a]>d[b]) swap(a, b);
    int diff=d[b]-d[a], ret;
    ret=diff;
    for(int i=20; i--;)
    {
        if(diff & (1<<i)) b=p[i][b];
    }

    if(a==b) return ret;
    for(int i=20; i--;)
    {
        if(p[i][a]!=p[i][b])
        {
            ret+=1<<(i+1);
            a=p[i][a], b=p[i][b];
        }
    }

    return ret+2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;

    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    for(int i=1; i<20; i++)
    {
        for(int j=1; j<=n; j++)
        {
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }

    int m, x, ans=0;
    cin>>m>>x;
    while(--m)
    {
        int y;
        cin>>y;
        ans+=lca(x, y);
        x=y;
    }
    cout<<ans;
}