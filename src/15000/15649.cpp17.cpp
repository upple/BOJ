#include <bits/stdc++.h>
using namespace std;

int n, m;
bool v[10];
vector<int> arr;
void solve(int c)
{
	if(c==m)
	{
		for(int i : arr)
		{
			cout<<i<<" ";
		}

		cout<<"\n";
		return;
	}

	for(int i=1; i<=n; i++)
	{
		if(!v[i])
		{
			arr.push_back(i);
			v[i]=1;
			solve(c+1);
			v[i]=0;
			arr.pop_back();
		}
	}
}
int main()
{
	cin>>n>>m;
	solve(0);
}