#include<bits/stdc++.h>
using namespace std;

int n, m, s, e;
bool v[10001];
struct edge
{
    int v, c;
};

vector<vector<edge> > adj;

bool bfs(int cost)
{
    memset(v, 0, sizeof(v));
    queue<int> Q;
    Q.push(s);
    v[s]=1;
    while(Q.size())
    {
        int cur=Q.front();
        Q.pop();
        if(cur==e) return true;
        for(auto i : adj[cur])
        {
            if(v[i.v]==0 && i.c>=cost)
            {
                Q.push(i.v);
                v[i.v]=1;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int l, r=-1;
    adj.resize(n+1);
    while(m--)
    {
        int a, b, c;
        cin>>a>>b>>c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        r=max(r, c);  
    }

    cin>>s>>e;
    l=1;
    int ans=-1;
    while(l<=r)
    {
        int mid=l+r>>1;

        if(bfs(mid))
        {
            l=mid+1;
            ans=max(ans, mid);
        }
        else
        {
            r=mid-1;
        }
    }

    cout<<ans;

}