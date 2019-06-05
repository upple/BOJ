#include <bits/stdc++.h>
using namespace std;

vector<int> num={1, 5, 10, 50};
unordered_set<int> S[3];

void solve(int n, int c, unordered_set<int> &s)
{
	if(n==0)
	{
		s.insert(c);
		return;
	}

	for(int x : num)
	{
		solve(n-1, c+x, s);
	}
}
int main()
{
	int n;
	cin>>n;

	solve(n/2, 0, S[0]);
	solve(n/2+(n%2), 0, S[1]);

	for(int i : S[0])
	{
		for(int j : S[1])
		{
			S[2].insert(i+j);
		}
	}

	cout<<S[2].size();
}