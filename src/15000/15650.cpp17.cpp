#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;
void solve(int x, int c)
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

	for(int i=x+1; i<=n; i++)
	{
		arr.push_back(i);
		solve(i, c+1);
		arr.pop_back();
	}
}

int main()
{
	cin>>n>>m;
	solve(0, 0);
}