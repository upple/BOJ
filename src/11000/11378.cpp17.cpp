#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> adj[1001];
int p[1001];
bool v[1001];

bool dfs(int x)
{
    v[x]=1;
    for(int i : adj[x])
    {
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
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
    {
        int s;
        cin>>s;
        adj[i].resize(s);
        for(int &j : adj[i])
            cin>>j;
    }

    int match=0;
    for(int i=1; i<=n; i++)
    {
        memset(v, 0, n+1);
        if(dfs(i)) match++;
    }

    for(int i=1; i<=n && match<m; i++)
    {
        while(k)
        {
            memset(v, 0, n+1);
            if(!dfs(i)) break;

            match++;
            k--;
        }
        
    }

    cout<<match;
}