#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

struct edge{int v, c;};
vector<edge> adj[4001];
vector<int> d1;
<<<<<<< HEAD
vector<vector<int> > d2;
vector<bool> inQ;
vector<vector<bool> >inQ2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int n, m;
	cin>>n>>m;
	d1.assign(n+1, INF);
	d2.assign(2, vector<int>(n+1, INF));
=======
vector<vector<double> > d2;
vector<bool> inQ;
vector<vector<bool> >inQ2;
int main()
{
	int n, m;
	cin>>n>>m;
	d1.assign(n+1, INF);
	d2.assign(2, vector<double>(n+1, INF));
>>>>>>> 0377fb96ed2a7791d61a646928ae09bd7f65daf4
	while(m--)
	{
		int a, b, d;
		cin>>a>>b>>d;
<<<<<<< HEAD
		adj[a].push_back({b, d*2});
		adj[b].push_back({a, d*2});
=======
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
>>>>>>> 0377fb96ed2a7791d61a646928ae09bd7f65daf4
	}

	inQ.assign(n+1, false);
	inQ2.assign(2, vector<bool>(n+1, false));
<<<<<<< HEAD

	queue<int> Q;
	d1[1]=0;
	Q.push(1);

=======
	queue<int> Q;
	d1[1]=0;
	Q.push(1);
>>>>>>> 0377fb96ed2a7791d61a646928ae09bd7f65daf4
	while(Q.size())
	{
		int cur=Q.front();
		Q.pop();
		inQ[cur]=0;
		for(auto &next : adj[cur])
		{
			if(d1[next.v]>d1[cur]+next.c)
			{
				d1[next.v]=d1[cur]+next.c;
<<<<<<< HEAD
				if(!inQ[next.v]) inQ[next.v]=1, Q.push(next.v);
=======
				if(!inQ[next.v])
				{
					inQ[next.v]=1, Q.push(next.v);
				}
>>>>>>> 0377fb96ed2a7791d61a646928ae09bd7f65daf4
			}
		}
	}

	queue<edge> Q2;
	d2[0][1]=0;
	Q2.push({1, 0});
<<<<<<< HEAD

=======
>>>>>>> 0377fb96ed2a7791d61a646928ae09bd7f65daf4
	while(Q2.size())
	{
		int cur=Q2.front().v, c=Q2.front().c;
		Q2.pop();
		inQ2[c][cur]=0;
		for(auto &next : adj[cur])
		{
			if(d2[!c][next.v]>(c==0?0.5:2)*next.c+d2[c][cur])
			{
				d2[!c][next.v]=(c==0?0.5:2)*next.c+d2[c][cur];
<<<<<<< HEAD
				if(!inQ2[!c][next.v]) inQ2[!c][next.v]=1, Q2.push({next.v, !c});
=======
				if(!inQ2[!c][next.v])
				{
					inQ2[!c][next.v]=1, Q2.push({next.v, !c});
				}
>>>>>>> 0377fb96ed2a7791d61a646928ae09bd7f65daf4
			}
		}
	}

	int ans=0;
	for(int i=2; i<=n; i++)
<<<<<<< HEAD
		if(d1[i]<min(d2[0][i], d2[1][i])) ans++;
=======
	{
		if(d1[i]<min(d2[0][i], d2[1][i])) ans++;
	}
>>>>>>> 0377fb96ed2a7791d61a646928ae09bd7f65daf4

	cout<<ans;
}