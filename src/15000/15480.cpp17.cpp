#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

vector<int> adj[MAX];
int p[20][MAX], d[MAX];

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

int lca(int u, int v)
{
    if(d[u]>d[v]) swap(u, v);
    int diff=d[v]-d[u];
    for(int i=20; i--;)
    {
        if(diff & (1<<i)) v=p[i][v];
    }

    if(u==v) return u;
    for(int i=20; i--;)
    {
        if(p[i][u]!=p[i][v]) u=p[i][u], v=p[i][v];
    }

    return p[0][u];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    for(int i=1; i<20; i++)
    {
        for(int j=1; j<=n; j++)
        {
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
    int m;
    cin>>m;
    while(m--)
    {
        int r, u, v, a, b, c, ans;
        cin>>r>>u>>v;
        a=lca(u, v);
        b=lca(r, u);
        c=lca(r, v);
        if(d[a]>d[b])
        {
            if(d[a]>d[c]) ans=a;
            else ans=c;
        }
        else
        {
            if(d[b]>d[c]) ans=b;
            else ans=c;
        }
        
        cout<<ans<<'\n';
    }
}