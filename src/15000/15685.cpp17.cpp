#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, -1, 0, 1 };
bool chk[101][101];
void solve(int x, int y, int d, int g)
{
	deque<int> v;
	v.push_back(d);
	while (g--)
	{
		stack<int> S;
		for (int i : v)
		{
			S.push((i + 1) % 4);
		}

		while (S.size())
		{
			v.push_back(S.top());
			S.pop();
		}
	}

	chk[x][y] = true;
	for (int i : v)
	{
		x += dx[i], y += dy[i];
		chk[x][y] = true;
	}
}
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		solve(x, y, d, g);
	}

	int ans = 0;
	for (int j = 0; j < 100; j++)
	{
		for (int i = 0; i < 100; i++)
		{
			if (chk[i][j] && chk[i + 1][j] && chk[i][j + 1] && chk[i + 1][j + 1]) ans++;
		}
	}

	cout << ans;
}