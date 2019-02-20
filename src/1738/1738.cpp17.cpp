#include <bits/stdc++.h>
#define NA 0xf0f0f0f0
using namespace std;

struct edge{int v, c;};
int cnt[101], d[101], p[101];
bool inQ[101];
vector<edge> adj[101];
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;
    while(m--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
    }

    memset(d, NA, sizeof(d));
    queue<int> Q;
    d[1]=0;
    Q.push(1);
    while(Q.size())
    {
        int cur=Q.front();
        Q.pop();
        inQ[cur]=0;
        cnt[cur]++;

        for(auto[next, c]: adj[cur])
        {
            if(d[next]<d[cur]+c && cnt[next]<n)
            {
                d[next]=d[cur]+c;
                p[next]=cur;
                if(!inQ[next])
                {
                    inQ[next]=1;
                    Q.push(next);
                }
            }
        }
    }

    if(d[n]==NA) cout<<-1;
    else
    {
        for(int cur=n; cur; cur=p[cur])
        {
            if(cnt[cur]==n)
            {
                cout<<-1;
                return 0;
            }
            ans.push_back(cur);
        }

        for(int i=ans.size(); i--;)
            cout<<ans[i]<<' ';
    }
}