#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int t[2001];
priority_queue<pair<int, pair<int, int> > > pq;
int main()
{
    int c, n, m, ans=0;
    cin>>n>>c>>m;
    while(m--)
    {
        int s, e, v;
        cin>>s>>e>>v;
        pq.push({-e, {-s, -v}});
    }

    while(pq.size())
    {
        int s=-pq.top().second.first, e=-pq.top().first;
        int v=-pq.top().second.second;
        pq.pop();

        int var = *max_element(t+s, t+e+1);
        int load = min(c-var, v);
        ans+=load;
        for(int i=s; i<e; i++)
            t[i]+=load;
        
    }

    cout<<ans;
}