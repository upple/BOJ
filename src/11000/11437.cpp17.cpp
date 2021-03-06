#include <bits/stdc++.h>
using namespace std;

vector<int> adj[50001];
bool v[500001];
int d[50001], p[22][50001];
void dfs(int x, int c)
{
    v[x]=1;
    d[x]=c;
    for(int i : adj[x])
    {
        if(!v[i]) 
        {
            p[0][i]=x;
            dfs(i, c+1);        
        }
    }
}

int query(int a, int b)
{
    if(d[a]>d[b]) swap(a, b);

    while(d[a]!=d[b])
    {
        int diff=d[b]-d[a];
        b=p[int(floor(log2(diff)))][b];
    }

    if(a==b) return a;
    for(int i=20; i>=0; i--)
    {
        if(p[i][a]!=p[i][b])
        {
            a=p[i][a];
            b=p[i][b];
        }
    }

    return p[0][a];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;

    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1);
    for(int i=1; i<=20; i++)
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
        int a, b;
        cin>>a>>b;
        cout<<query(a, b)<<"\n";
    }
}