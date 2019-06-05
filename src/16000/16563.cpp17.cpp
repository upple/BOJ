#include <bits/stdc++.h>
using namespace std;

vector<int> prime;
bool chk[5000001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for(int i=2; i<=2300; i++)
	{
		if(!chk[i])
		{
			prime.push_back(i);
			int t=i*i-i;
			while((t+=i)<=5000000)
			{
				chk[t]=1;
			}
		}
	}

	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		for(int p : prime)
		{
			if(x==1) break;
			if(chk[x]==0)
			{
				cout<<x;
				break;
			}
			while(x%p==0)
			{
				cout<<p<<' ';
				x/=p;
			}
		}
		cout<<'\n';
	}
}