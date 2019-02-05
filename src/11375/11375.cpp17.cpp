#include <bits/stdc++.h>
using namespace std;
int n, m;

vector<int> adj[1001];
int p[1001];
bool v[1001];

bool dfs(int x)
{
    v[x]=1;
    for(int i : adj[x])
    {
        if(p[i]==x) continue;
        if(!p[i] || (!v[p[i]] && dfs(p[i])))
        {
            p[i]=x;
            return true;
        }
    }

    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        int c;
        cin>>c;
        while(c--)
        {
            int x;
            cin>>x;
            adj[i].push_back(x);
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        memset(v, 0, sizeof(v));
        if(dfs(i)) ans++;
    }

    cout<<ans;
}