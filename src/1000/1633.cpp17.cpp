#include <bits/stdc++.h>
#define MAX 1004
#define INF 0x3f3f3f3f
using namespace std;

struct edge
{
	int v, f, c;
	edge* rvs;
	edge(int _v, int _f, int _c) : v(_v), f(_f), c(_c), rvs(0) {}
};
int S, E, B, W, n;
vector<edge*> adj[MAX];
int p[MAX], d[MAX];
edge *path[MAX];
bool inQ[MAX];

void connect_edge(int a, int b, int f, int c)
{
	edge *e1, *e2;
	e1=new edge(b, f, c);
	e2=new edge(a, 0, -c);
	e1->rvs=e2, e2->rvs=e1;
	adj[a].push_back(e1), adj[b].push_back(e2);
}

bool spfa()
{
	memset(d, INF, sizeof(d));
	queue<int> Q;
	Q.push(S);
	d[S]=0;
	while(Q.size())
	{
		int cur=Q.front();
		Q.pop();
		inQ[cur]=0;
		
		for(edge *e : adj[cur])
		{
			int v=e->v, f=e->f, c=e->c;
			if(f>0 && d[v]>d[cur]+c)
			{
				d[v]=d[cur]+c;
				path[v]=e;
				p[v]=cur;
				if(!inQ[v]) inQ[v]=1, Q.push(v);
			}
		}
	}
	return d[E]!=INF;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int a, b;
	S=0, B=1001, W=1002, E=1003;
	connect_edge(B, E, 15, 0);
	connect_edge(W, E, 15, 0);

	while(cin>>a>>b)
	{
		n++;
		connect_edge(S, n, 1, 0);
		connect_edge(n, B, 1, -a);
		connect_edge(n, W, b, -b);
	}

	int ans=0;
	while(spfa())
	{
		for(int i=E; i!=S; i=p[i])
		{
			ans-=(path[i]->c);
			path[i]->f--;
			path[i]->rvs->f++;
		}
	}

	cout<<ans;
}