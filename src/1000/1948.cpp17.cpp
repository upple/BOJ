#include <bits/stdc++.h>
using namespace std;
const int INF=-1;
struct edge{int v, c;};
int n, m;
vector<edge> adj[100001], rvs[100001];
int in[100001], dist[100001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    while(m--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
        rvs[b].push_back({a, c});
        in[b]++;
    }

    int s, t;
    int cnt=0;
    cin>>s>>t;
    queue<int> Q;
    Q.push(s);
    memset(dist, INF, sizeof(dist));
    dist[s]=0;
    while(Q.size())
    {
        int cur=Q.front();
        Q.pop();

        for(auto &[next, cost] : adj[cur])
        {
            dist[next]=max(dist[next], dist[cur]+cost);
            if(--in[next]==0)
            {
                Q.push(next);
            }
        }
    }

    Q.push(t);
    in[t]=1;
    while(Q.size())
    {
        int cur=Q.front();
        Q.pop();

        for(auto &[next, cost] : rvs[cur])
        {
            if(dist[cur]-cost==dist[next])
            {
                if(in[next]==0) Q.push(next);
                in[next]=1;
                cnt++;
            }
        }
    }
    
    cout<<dist[t]<<'\n'<<cnt;
}