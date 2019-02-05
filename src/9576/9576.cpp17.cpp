#include <bits/stdc++.h>
using namespace std;
int n, m;

vector<int> adj[1001];
int p[1001], l[1001], r[1001];
bool v[1001];

bool dfs(int x)
{
    v[x]=1;
    for(int i=l[x]; i<=r[x]; i++)
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
    
    int t;
    cin>>t;
    while(t--)
    {    
        cin>>n>>m;
        for(int i=1; i<=m; i++)
        {
            cin>>l[i]>>r[i];
        }
        memset(p, 0, sizeof(p));
        int ans=0;
        for(int i=1; i<=m; i++)
        {
            memset(v, 0, sizeof(v));
            if(dfs(i)) ans++;
        }

        cout<<ans<<'\n';

    }
    
}