#include <bits/stdc++.h>
using namespace std;

int w[10][10];
bool v[10];
int n, ans=99999999, cur, s;

void solve(int c, int x)
{
	if(c==n) 
	{
		if(w[x][s])
		{
			cur+=w[x][s];
			ans=min(ans, cur);
			cur-=w[x][s];
		}
		return;
	}

	for(int i=0; i<n; i++)
	{
		if(!v[i] && w[x][i])
		{
			v[i]=1;
			cur+=w[x][i];
			solve(c+1, i);
			cur-=w[x][i];
			v[i]=0;
		}
	}
}
int main()
{
	cin>>n;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>w[i][j];
		}
	}

	for(s=0; s<n; s++)
	{
		v[s]=1;
		solve(1, s);
		v[s]=0;
	}
	cout<<ans;
}