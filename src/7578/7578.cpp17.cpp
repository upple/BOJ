#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int tree[500001];

int n;
long long ans=0;
void update(int p)
{
	while(p<=n)
	{
		tree[p]++;
		p+=p&-p;
	}
}

long long query(int p)
{
	int ret=0;
	while(p)
	{
		ret+=tree[p];
		p-=p&-p;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		int x;
		cin>>x;
		arr[x]=i;
	}

	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		x=arr[x];
		ans+=i-query(x);
		update(x);
	}
	cout<<ans;
}