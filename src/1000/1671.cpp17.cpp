#include <bits/stdc++.h>
using namespace std;
struct shark
{
	int size, speed, intel;
};
inline bool operator >= (shark a, shark b)
{
	return a.size>=b.size && a.speed>=b.speed && a.intel>=b.intel;
}
int p[51];
bool v[51];
shark arr[51];
int n;

bool dfs(int x)
{
	v[x]=1;
	for(int i=1; i<=n; i++)
	{
		if(p[i]==x || x==i || !(arr[x]>=arr[i])) continue;
		if(arr[i]>=arr[x] && i<x) continue;
		if(p[i]==0 || (v[p[i]]==0 && dfs(p[i])))
		{
			p[i]=x;
			return true;
		}
	}
	return false;
}

int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		arr[i]={a, b, c};
	}

	int remain=n;
	for(int i=1; i<=n; i++)
	{
		memset(v, 0, n+1);
		if(dfs(i))
		{
			memset(v, 0, n+1);
			remain-=dfs(i)+1;
		}
	}

	cout<<remain;
}