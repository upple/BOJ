#include <bits/stdc++.h>
using namespace std;

int o[]={0, 6, 4, 5, 2, 3, 1};
int dice[7][10000];
int n;

int solve(int c, int x)
{
	int ret=0;
	for(int i=1; i<=6; i++)
	{
		if(dice[c][x]==i || dice[o[c]][x]==i) continue;
		ret=max(ret, i);
	}

	if(x==n-1) return ret;
	for(int i=1; i<=6; i++)
	{
		if(dice[i][x+1]==dice[o[c]][x])
			return ret+=solve(i, x+1);
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=1; j<=6; j++)
			cin>>dice[j][i];
    
	int ans=0;
	for(int i=1; i<=6; i++)
		ans=max(ans, solve(i, 0));

	cout<<ans;
}