#include <bits/stdc++.h>
using namespace std;

vector<int> c;
bool dp[40001];
int main()
{
	int n;
	cin>>n;
	c.resize(n);
	for(int i=0; i<n; i++)
	{
		cin>>c[i];
	}

	dp[0]=1;
	queue<int> Q;
	Q.push(0);
	for(int i=0; i<n; i++)
	{
		for(int size=Q.size(); size--;)
		{
			int cur=Q.front();
			Q.pop();
			Q.push(cur);
			if(cur+c[i]>40000|| dp[cur+c[i]]) continue;
			dp[cur+c[i]]=1;
			Q.push(cur+c[i]);
		}
	}

	int m;
	cin>>m;
	while(m--)
	{
		int x;
		cin>>x;
		queue<int> Q;
		bool v[40001]={};
		Q.push(x);
		v[x]=1;
		for(int i=0; i<n; i++)
		{
			for(int size=Q.size(); size--;)
			{
				int cur=Q.front();
				Q.pop();
				Q.push(cur);
				if(dp[cur])
				{
					cout<<"Y ";
					goto out;
				}
				if(cur+c[i]>40000 || v[cur+c[i]]) continue;
				v[cur+c[i]]=1;
				Q.push(cur+c[i]);
			}
		}

		cout<<"N ";
		out:;
	}
}