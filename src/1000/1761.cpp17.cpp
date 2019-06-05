#include <bits/stdc++.h>
#define MAX 40001
using namespace std;
struct edge{int v, c;};
vector<edge> adj[MAX];
int p[20][MAX], d[MAX], cost[20][MAX];
bool v[MAX];
void dfs(int cur)
{
    v[cur]=1;
    for(auto next : adj[cur])
    {
        if(!v[next.v])
        {
            p[0][next.v]=cur;
            cost[0][next.v]=next.c;
            d[next.v]=d[cur]+1;
            dfs(next.v);
        }
    }
}

int lca(int a, int b)
{
    if(d[a]>d[b]) swap(a, b);
    int diff=d[b]-d[a], ret=0;
    for(int i=20; i--;)
    {
        if(diff & (1<<i)) 
        {
            ret+=cost[i][b];
            b=p[i][b];
        }
    }

    if(a==b) return ret;

    for(int i=20; i--;)
    {
        if(p[i][a] != p[i][b]) 
        {
            ret+=cost[i][a]+cost[i][b];
            a=p[i][a], b=p[i][b];
        }
    }

    return ret+cost[0][a]+cost[0][b];
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
            cost[i][j]=cost[i-1][p[i-1][j]]+cost[i-1][j];
        }
    }

    cin>>m;
    while(m--)
    {
        int a, b;
        cin>>a>>b;
        cout<<lca(a, b)<<'\n';
    }
}