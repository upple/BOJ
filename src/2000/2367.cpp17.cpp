#include <bits/stdc++.h>
#define S 0
#define E 301
using namespace std;

struct edge
{
    int v, f;
    edge *rvs;
    edge(int _v, int _f) : v(_v), f(_f), rvs(0) {}
};

int n, k, d;
vector<edge*> adj[302];
int level[302], chk[302];

void connect_edge(int a, int b, int f)
{
    edge *e1, *e2;
    e1=new edge(b, f);
    e2=new edge(a, 0);
    e1->rvs=e2;
    e2->rvs=e1;
    adj[a].push_back(e1);
    adj[b].push_back(e2);
}

bool bfs()
{
	memset(level, 0, sizeof(level));
    queue<int> Q;
    Q.push(S);
	level[S]=1;

    while(Q.size())
    {
        int cur=Q.front();
        Q.pop();
        if(cur==E) return true;

        for(edge *e : adj[cur])
        {
            int u=e->v, f=e->f;
            if(f>0 && !level[u])
            {
                level[u]=level[cur]+1;
                Q.push(u);
            }
        }
    }

    return level[E];
}

int dfs(int cur, int flow)
{
	if(cur==E) return flow;
	int ret=0;
	for(int &i=chk[cur]; i<adj[cur].size(); i++)
	{
		int next=adj[cur][i]->v, &f=adj[cur][i]->f;
		if(f>0 && level[next]==level[cur]+1)
		{
			int min_flow=dfs(next, min(flow, f));
			
			f-=min_flow;
			adj[cur][i]->rvs->f+=min_flow;
			flow-=min_flow;
			ret+=min_flow;
			if(flow==0) break;
		}
	}

	return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k>>d;
    for(int i=1; i<=d; i++)
    {
        int x;
        cin>>x;
        connect_edge(i+200, E, x);
    }
    for(int i=1; i<=n; i++)
    {
        connect_edge(S, i, k);
        int c;
        cin>>c;
        while(c--)
        {
            int x;
            cin>>x;
            connect_edge(i, x+200, 1);
        }
    }

    int ans=0;
    while(bfs())
    {
		memset(chk, 0, sizeof(chk));
		ans+=dfs(S, 1e9);
    }

    cout<<ans;
}