#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr, input;
void solve(int c)
{
	if(c==m)
	{
		for(int i : arr)
			cout<<i<<" ";

		cout<<"\n";
		return;
	}

	for(int i=0; i<n; i++)
	{
		arr.push_back(input[i]);
		solve(c+1);
		arr.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin>>n>>m;
	input.resize(n);
	for(int i=0; i<n; i++)
		cin>>input[i];

	sort(input.begin(), input.end());
	solve(0);
}