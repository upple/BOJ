#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin>>n>>k;
	priority_queue<long long> pq;
	for(int i=0; i<n; i++)
	{
		long long x;
		cin>>x;
		pq.push(-x);

	}

	long long ans=0;
	int cnt=0;
	while(pq.size())
	{
		ans+=-pq.top()*min(cnt, k);
		cnt++;
		pq.pop();
	}

	cout<<ans;
}