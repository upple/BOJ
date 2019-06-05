#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, k, cnt=0, ans=0;
	scanf("%d %d", &n, &k);
	
	vector<queue<int> > adj(k+1);
	vector<int> arr(k+1), visit(k+1);
	for(int i=1; i<=k; i++)
	{
		scanf("%d", &arr[i]);
		adj[arr[i]].push(i);
	}
	
	priority_queue<pair<int, int> > use;
	for(int i=1; i<=k; i++)
	{
		int cur=arr[i];
		if(!visit[cur])
		{
			if(cnt==n)
			{
				while(!visit[use.top().second])
				{
					use.pop();
				}
				visit[use.top().second]=0;
				use.pop();
				ans++;
			}
			
			else
			{
				cnt++;
			}
			visit[cur]=1;
			
		}
		adj[cur].pop();
		
		if(adj[cur].empty())
			use.push({99999, cur});
		
		else
			use.push({adj[cur].front(), cur});
		
	}
	
	printf("%d", ans);
}