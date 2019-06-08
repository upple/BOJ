#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> order;
bool v[21][21][21];
int n, a, b, x, m;
int bfs()
{
	int cnt = 0;
	queue<int> Q;
	Q.push(a * 10000 + b * 100);
	v[a][b][0] = 1;
	while (Q.size())
	{
		int size = Q.size();
		while (size--)
		{
			int l = Q.front() / 10000, r = Q.front() % 10000 / 100;
			int c = Q.front() % 100;
			Q.pop();

			while (c < m && (l == order[c] || r == order[c])) v[l][r][++c] = 1;
			if (c == m) return cnt;
			if (r - l > 1)
			{
				if (!v[l + 1][r][c])
				{
					Q.push((l + 1) * 10000 + r * 100 + c);
					v[l + 1][r][c] = 1;
				}
				if (!v[l][r - 1][c])
				{
					Q.push(l * 10000 + (r - 1) * 100 + c);
					v[l][r - 1][c] = 1;
				}
			}
			if (l > 1 && !v[l - 1][r][c])
			{
				Q.push((l - 1) * 10000 + r * 100 + c);
				v[l - 1][r][c] = 1;
			}
			if (r < n && !v[l][r + 1][c])
			{
				Q.push(l * 10000 + (r + 1) * 100 + c);
				v[l][r + 1][c] = 1;
			}
		}
		cnt++;
	}

}
int main()
{
	cin >> n >> a >> b >> m;
	if (a > b) swap(a, b);
	order.resize(m);
	for (int &i : order) cin >> i;

	cout << bfs();
}