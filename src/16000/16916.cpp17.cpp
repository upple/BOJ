#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef unsigned int ui;
const ui m[]={(ui)1e9+7, (ui)1e9+27};
ui p[2][1000001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string a, b;
	cin>>a>>b;
	p[0][0]=p[1][0]=1;
	for(int i=1; i<b.size(); i++)
	{
		for(int j=2; j--;)
		{
			p[j][i]=p[j][i-1]*m[j];
		}
	}

	ui h[2]={};
	ull ahash, bhash;
	for(int i=0; i<b.size(); i++)
	{
		for(int j=2; j--;)
		{
			h[j]=h[j]*m[j]+b[i];
		}
	}

	bhash=((ull)h[0]<<32)+h[1];

	h[0]=h[1]=0;
	for(int i=0; i<b.size(); i++)
	{
		for(int j=2; j--;)
		{
			h[j]=h[j]*m[j]+a[i];
		}
	}

	ahash=((ull)h[0]<<32)+h[1];
	if(ahash==bhash)
	{
		cout<<1;
		return 0;
	}
	for(int i=b.size(); i<a.size(); i++)
	{
		for(int j=2; j--;)
		{
			h[j]-=p[j][b.size()-1]*a[i-b.size()];
			h[j]=h[j]*m[j]+a[i];
		}

		ahash=((ull)h[0]<<32)+h[1];
		if(ahash==bhash)
		{
			cout<<1;
			return 0;
		}
	}

	cout<<0;
}