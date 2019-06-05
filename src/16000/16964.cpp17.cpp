#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int p[100001], c[100001];

void dfs(int x)
{
    for(int next : adj[x])
    {
        if(!p[next])
        {
            p[next]=x;
            c[x]++;
            dfs(next);
        }
    }
}

bool solve(int x)
{
    for(int i=0; i<c[x]; i++)
    {
        int y;
        cin>>y;
        if(p[y]!=x || !solve(y)) return false;
    }

    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=n; --n;)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    p[1]=-1;
    dfs(1);
    int x;
    cin>>x;
    if(x!=1) cout<<0;
    else cout<<solve(1);
}