#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > adj[1001];
priority_queue<pair<int, int> > pq;
bool v[1001];
int n, m, ans;
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
        adj[b].push_back({a, c});
    }
    pq.push({0, 1});
    while(n)
    {
        int cur=pq.top().second, cost=-pq.top().first;
        pq.pop();
        if(v[cur]) continue;
        v[cur]=1;
        ans+=cost;
        n--;

        for(auto &i : adj[cur])
        {
            int nv=i.first, nc=i.second;
            if(!v[nv]) pq.push({-nc, nv});
        }
    }

    cout<<ans;
}