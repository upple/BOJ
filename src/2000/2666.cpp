#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int order[21];
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
			
			for (int i = 4; i--;)
			{
				int nl = l + dx[i], nr = r + dy[i];
				if (nl > 0 && nr <= n && nr - nl > 0 && !v[nl][nr][c])
				{
					Q.push(nl * 10000 + nr * 100 + c);
					v[nl][nr][c] = 1;
				}

			}
		}
		cnt++;
	}

}
int main()
{
	cin >> n >> a >> b >> m;
	if (a > b) swap(a, b);
	for (int i = 0; i < m; i++) cin >> order[i];

	cout << bfs();
}