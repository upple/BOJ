#include <bits/stdc++.h>
using namespace std;

vector<int> num={1, 5, 10, 50};
unordered_set<int> s;

void solve(int n, int c)
{
	if(n==0)
	{
		s.insert(c);
		return;
	}

	for(int x : num)
	{
		solve(n-1, c+x);
	}
}

int main()
{
	int n;
	cin>>n;

	if(n<12)
	{
		solve(n, 0);
		cout<<s.size();
	}
	else
	{
		solve(11, 0);
		cout<<s.size()+49LL*(n-11);
	}

}