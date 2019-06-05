#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;
struct xy{ int x, y; };
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
char arr[52][52];
int cost[52][52];
bool v[52][52];
int px, py, cnt, maxr;

int bfs(int left)
{
	int l = left, r = maxr;
	if (left > cost[px][py]) return -1;
	int ret = 1e9;
	while (l <= r)
	{
		int right = l + r >> 1, lcnt = 0;
		if (right < cost[px][py])
		{
			l = right + 1;
			continue;
		}
		memset(v, 0, sizeof(v));
		queue<xy> Q;
		Q.push({ px, py });
		v[px][py] = 1;
		while (Q.size())
		{
			int x = Q.front().x, y = Q.front().y;

			if (arr[x][y] == 'K') lcnt++;
			if (cnt == lcnt)
			{
				r = right - 1;
				ret = min(ret, right);
				break;
			}
			Q.pop();
			for (int i = 8; i--;)
			{
				int nx = x + dx[i], ny = y + dy[i];
				if (v[nx][ny] || !arr[nx][ny] || cost[nx][ny]<left || cost[nx][ny]>right) continue;
				Q.push({ nx, ny });
				v[nx][ny] = 1;
			}
		}

		if (Q.empty()) l = right + 1;
	}

	if (ret == 1e9) return -1;
	else return ret - left;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i] + 1;
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 'P')
			{
				px = i, py = j;
			}
			else if (arr[i][j] == 'K')
			{
				cnt++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> cost[i][j];
			maxr = max(maxr, cost[i][j]);
		}
	}
	int l = 1, r = cost[px][py];
	int ans = 1e9;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int mid = cost[i][j];
			int ret = bfs(mid);
			if (ret != -1) ans = min(ans, ret);
		}
		
	}

	cout << ans;
}