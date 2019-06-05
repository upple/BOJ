#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > adj[100001];
int v[100001], m[100001];
int bfs(int a, int b)
{
    queue<int> Q;
    Q.push(a);
    while(Q.size())
    {
        int cur=Q.front();
        Q.pop();
        if(cur==b) return v[cur]-m[cur];

        for(auto &[next, cost] : adj[cur])
        {
            if(v[next]==0)
            {
                v[next]=v[cur]+cost;
                m[next]=max(m[cur], cost);
                Q.push(next);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin>>n>>a>>b;

    while(--n)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout<<bfs(a, b);
}