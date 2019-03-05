#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1)
    {
        vector<pair<int, int> > adj[200000];
        bool visit[200000]={};
        int n, m, r, sum=0;
        cin>>n>>m;
        if(n==0)
            return 0;
            
        r=n;
        while(m--)
        {
            int x, y, z;
            cin>>x>>y>>z;
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
            sum+=z;
        }

        priority_queue<pair<int, int> > pq;
        pq.push({0, 0});
        while(1)
        {
            int v=pq.top().second, c=-pq.top().first;
            pq.pop();
            if(visit[v]) continue;
            visit[v]=1;
            sum-=c;
            r--;
            if(!r)
            {
                cout<<sum<<"\n";
                goto out;
            }

            for(auto &i : adj[v])
            {
                int nv=i.first, nc=i.second;
                if(!visit[nv])
                    pq.push({-nc, nv});
            }
        }
        out:;
    }
}