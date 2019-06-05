#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int w[16][26], c[16], k[26];

int solve(int n, int cost)
{
	if(n<0)
	{
		for(int i=0; i<26; i++)
		{
			if(k[i]) return INF;
		}

		return cost;
	}

	int ret=INF, t[26];
	ret=min(ret, solve(n-1, cost));

	for(int i=0; i<26; i++)
	{
		t[i]=min(k[i], w[n][i]);
		k[i]-=t[i];
	}
	
	ret=min(ret, solve(n-1, cost+c[n]));
	for(int i=0; i<26; i++)
	{
		k[i]+=t[i];
	}

	return ret;
}
int main()
{
	string T, S;
	int n;
	cin>>T>>n;
	for(char a : T)
		k[a-'A']++;

	for(int i=0; i<n; i++)
	{
		cin>>c[i]>>S;
		for(char a : S)
		{
			w[i][a-'A']++;
		}
	
	}

	int ans=solve(n-1, 0);
	cout<<(ans==INF?-1:ans);
}