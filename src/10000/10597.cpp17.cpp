#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
vector<int> ans;
bool chk[51] = { 1, };
void solve(int x, int c)
{
	if (x == str.size())
	{
		for (int i = 1; i <= c; i++)
			if (!chk[i]) return;

		for (int i : ans)
			cout << i << ' ';

		exit(0);
	}

	if (x > str.size()) return;

	if (x < str.size())
	{
		int n = stoi(str.substr(x, 1));
		if (n <= 50 && !chk[n])
		{
			chk[n] = 1;
			ans.push_back(n);
			solve(x + 1, c+1);
			ans.pop_back();
			chk[n] = 0;
		}
	}

	if (x < str.size() - 1)
	{
		int n = stoi(str.substr(x, 2));
		if (n <= 50 && !chk[n])
		{
			chk[n] = 1;
			ans.push_back(n);
			solve(x + 2, c+1);
			ans.pop_back();
			chk[n] = 0;
		}
	}
}
int main()
{
	cin >> str;
	solve(0, 0);
}