#include <bits/stdc++.h>
using namespace std;

int a[10001], coin[100];
int main()
{
	int n, k;
	cin>>n>>k;

	for(int i=0; i<n; i++)
	{
		cin>>coin[i];
	}

	int t=0;
	while(t<=k)
	{
		a[t]=1;
		t+=coin[0];
	}

	for(int i=1; i<n; i++)
	{
		for(int j=0; j<=k; j++)
		{
			if(a[j]==0 || j+coin[i]>k) continue;
			a[j+coin[i]]+=a[j];
		}
	}

	cout<<a[k];
}