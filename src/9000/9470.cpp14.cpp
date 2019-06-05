#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int k, m, p;
		cin>>k>>m>>p;
		
		vector<int> max_order(m+1), cnt(m+1), in(m+1);
		vector<vector<int> > adj(m+1);
		while(p--)
		{
			int a, b;
			cin>>a>>b;
			adj[a].push_back(b);
			in[b]++;
		}

		queue<int> Q;
		for(int i=1; i<=m; i++)
		{
			if(in[i]==0) 
			{
				Q.push(i);
				max_order[i]=1;
				cnt[i]=1;
			}
		}

		int ans=0;
		while(Q.size())
		{
			int cur=Q.front();
			Q.pop();
			if(cnt[cur]>1) max_order[cur]++;

			ans=max(ans, max_order[cur]);
			for(int i : adj[cur])
			{
				if(max_order[cur]>max_order[i])
				{
					max_order[i]=max_order[cur];
					cnt[i]=1;
				}
				else if(max_order[i]==max_order[cur])
				{
					cnt[i]++;
				}

				if(--in[i]==0) Q.push(i);
			}
		}

		cout<<k<<" "<<ans<<"\n";
	}
}