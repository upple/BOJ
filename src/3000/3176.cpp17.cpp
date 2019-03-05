#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
struct edge{int v, c;};
vector<edge> adj[MAX];
int p[20][MAX], d[MAX], lo[20][MAX], hi[20][MAX];
bool v[MAX];
void dfs(int cur)
{
    v[cur]=1;
    for(auto next : adj[cur])
    {
        if(!v[next.v])
        {
            p[0][next.v]=cur;
            hi[0][next.v]=lo[0][next.v]=next.c;
            d[next.v]=d[cur]+1;
            dfs(next.v);
        }
    }
}

pair<int, int> lca(int a, int b)
{
    if(d[a]>d[b]) swap(a, b);
    int diff=d[b]-d[a], l=1e9, h=-1;
    for(int i=20; i--;)
    {
        if(diff & (1<<i)) 
        {
            l=min(l, lo[i][b]);
            h=max(h, hi[i][b]);
            b=p[i][b];
        }
    }

    if(a==b) return {l, h};

    for(int i=20; i--;)
    {
        if(p[i][a] != p[i][b]) 
        {
            l=min({l, lo[i][a], lo[i][b]});
            h=max({h, hi[i][a], hi[i][b]});
            a=p[i][a], b=p[i][b];
        }
    }

    l=min({l, lo[0][a], lo[0][b]});
    h=max({h, hi[0][a], hi[0][b]});
    return {l, h};
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n;

    for(int i=1; i<n; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dfs(1);
    for(int i=1; i<20; i++)
    {
        for(int j=1; j<=n; j++)
        {
            p[i][j]=p[i-1][p[i-1][j]];
            lo[i][j]=min(lo[i-1][j], lo[i-1][p[i-1][j]]);
            hi[i][j]=max(hi[i-1][j], hi[i-1][p[i-1][j]]);
        }
    }

    cin>>m;
    while(m--)
    {
        int a, b;
        cin>>a>>b;
        auto ans=lca(a, b);
        cout<<ans.first<<' '<<ans.second<<'\n';
    }
}