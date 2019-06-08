#include <bits/stdc++.h>
using namespace std;

int p[10001];
pair<int, int> c[10001];

int Find(int a)
{
	if(p[a]==a) return a;
	return p[a]=Find(p[a]);
}

void Union(int a, int b)
{
	if(a>b) p[a]=b;
	else p[b]=a;
}
int main()
{
	int n, m, k;
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)
	{
		p[i]=i;
		cin>>c[i-1].first;
		c[i-1].second=i;
	}
	while(m--)
	{
		int a, b;
		cin>>a>>b;
		Union(Find(a), Find(b));
	}
	sort(c, c+n);
	int cur=0;
	for(int i=0; i<n; i++)
	{
		if(cur+c[i].first>k) break;
		if(!Find(c[i].second)) continue;
		cur+=c[i].first;
		Union(0, Find(c[i].second));
	}

	for(int i=1; i<=n; i++)
		if(Find(i)!=0)
		{
			cout<<"Oh no";
			return 0;
		}

	cout<<cur;
}