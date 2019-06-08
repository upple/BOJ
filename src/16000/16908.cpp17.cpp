#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
typedef unsigned int ui;
const ui m1=128941, m2=453161;
vector<string> strs;
ui hashs[10][100001][2];
ui p1[MAX], p2[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;
	strs.resize(n);
	int l=1, r=1e9;
	for(int i=0; i<n; i++)
	{
		cin>>strs[i];
		if(r>strs[i].size());
			r=strs[i].size();
	}

	p1[0]=p2[0]=1;
	for(int i=1; i<r; i++)
		p1[i]=p1[i-1]*m1, p2[i]=p2[i-1]*m2;

	for(int i=0; i<n; i++)
	{
		for(int j=1; j<=r; j++)
		{
			hashs[i][j][0]=hashs[i][j-1][0]*m1+strs[i][j-1];
			hashs[i][j][1]=hashs[i][j-1][1]*m2+strs[i][j-1];
		}
	}
	int ans=0;

	while(l<=r)
	{
		int mid=l+r>>1;
		int _max=0;
		unordered_set<unsigned long long> S[10];
		for(int u=0; u<n; u++)
		{
			string &str=strs[u];
			ui hash1=hashs[u][mid][0], hash2=hashs[u][mid][1];
			unsigned long long hash=(((unsigned long long)hash1)<<32)+hash2;
			if(u==0 || S[u-1].find(hash)!=S[u-1].end())
				S[u].insert(hash);

			for(int i=mid; i<str.size(); i++)
			{
				hash1-=p1[mid-1]*str[i-mid];
				hash1=hash1*m1+str[i];
				
				hash2-=p2[mid-1]*str[i-mid];
				hash2=hash2*m2+str[i];
				
				hash=(((unsigned long long)hash1)<<32)+hash2;
				if(u==0 || S[u-1].find(hash)!=S[u-1].end())
					S[u].insert(hash);
			}

			if(S[u].size()==0) break;
		}

		if(S[n-1].size())
		{
			ans=max(ans, mid);
			l=mid+1;
		}
		else r=mid-1;
	}

	cout<<ans;
}