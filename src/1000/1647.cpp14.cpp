#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int> > adj[1000001];
priority_queue<pair<int, int> > pq;
bool v[1000001];
int n, m, ans, max_road;
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
        max_road=max(max_road, cost);
        n--;

        for(auto &i : adj[cur])
        {
            int nv=i.first, nc=i.second;
            if(!v[nv]) pq.push({-nc, nv});
        }
    }

    cout<<ans-max_road;
}