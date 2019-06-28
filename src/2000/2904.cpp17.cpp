#include <bits/stdc++.h>
using namespace std;

bool chk[1000001];
vector<vector<int> > cnt;
vector<int> prime;

int main()
{
	for(long long i=2; i<=1000000; i++)
	{
		if(!chk[i])
		{
			prime.push_back(int(i));
			long long t=i*i;
			while(t<=1000000)
			{
				chk[t]=1;
				t+=i;
			}

		}
	}

	int n;
	cin>>n;
	cnt.assign(prime.size(), vector<int>(n, 0));
	vector<int> avl(prime.size(), 0);
	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		int p=lower_bound(prime.begin(), prime.end(), x)-prime.begin();
		if(p==prime.size()) p--;

		while(x!=1 && p>=0)
		{
			while(x%prime[p]==0)
			{
				x/=prime[p];
				cnt[p][i]++;
				avl[p]++;
			}
			p--;
		}
	}

	int ans=0;
	int score=1;
	for(int i=0; i<prime.size(); i++)
	{
		int a=avl[i]/n;
		if(avl[i]<n) continue;
		for(int j=0; j<a; j++)
			score*=prime[i];

		for(int j=0; j<n; j++)
		{
			if(cnt[i][j]<a) ans+=a-cnt[i][j];
		}
	}

	cout<<score<<' '<<ans;
}