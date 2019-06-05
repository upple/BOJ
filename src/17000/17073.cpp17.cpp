#include <bits/stdc++.h>
using namespace std;

int chk[500001];
int cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	double w;
	cin>>n>>w;
	cnt=n;
	while(--n)
	{
		int u, v;
		cin>>u>>v;
		if(chk[u]==1) cnt--;
		if(chk[v]==1) cnt--;
		chk[u]++, chk[v]++;
	}

	if(chk[1]==1) cnt--;
	cout.precision(10);
	cout<<w/cnt;
}