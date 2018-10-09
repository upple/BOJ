#include <bits/stdc++.h>
using namespace std;

int arr[101], input[1000];
struct ob
{
	int c, t, x;
};
inline bool operator<(const ob& a, const ob& b)
{
	if(a.c==b.c) return a.t>b.t;
	return a.c>b.c;
}
int main()
{
	int n, m;
	cin>>n>>m;
	priority_queue<ob> pq;

	for(int i=0; i<m; i++)
	{
		int x;
		cin>>x;
		if(arr[x]==0)
		{
			if(pq.size()==n)
			{
				while(1)
				{
					int c=pq.top().c, t=pq.top().t, v=pq.top().x;
					pq.pop();
					if(arr[v]==c)
					{
						pq.push({1, i, x});
						arr[v]=0;
						arr[x]++;
						break;
					}
					else
					{
						pq.push({arr[v], t, v});
					}
				}
			}
			else
			{
				pq.push({1, i, x});
				arr[x]++;
			}
			
		}	
		else
		{
			arr[x]++;
		}	
	}

	for(int i=0; i<=100; i++)
	{
		if(!arr[i]) continue;
		cout<<i<<' ';
	}
}