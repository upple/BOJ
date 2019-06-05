#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;
void solve(int x, int c)
{
	if(c==m)
	{
		for(int i : arr)
			cout<<i<<" ";

		cout<<"\n";
		return;
	}

	for(int i=1; i<=n; i++)
	{
		arr.push_back(i);
		solve(i, c+1);
		arr.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin>>n>>m;
	solve(0, 0);
}