#include <bits/stdc++.h>
using namespace std;

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };
int r, c;
char arr[1502][1502];
int o[1502][1502];
bool v[1502][1502];
queue<int> BQ;
int L, R;
int a, b;
void queueing(int x, int y)
{
	queue<int> Q;
	v[x][y] = 1;
	Q.push((x << 11) | y);
	while (Q.size())
	{
		x = Q.front() >> 11, y = Q.front() & 0x7ff;
		Q.pop();
		for (int i = 4; i--;)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (v[nx][ny] || o[nx][ny]) continue;
			if (arr[nx][ny] == 'X')
			{
				BQ.push((nx << 11) | ny);
				o[nx][ny] = 1;
			}
			else if (arr[nx][ny] == '.')
			{
				Q.push((nx << 11) | ny);
				v[nx][ny] = 1;
			}
		}
	}
}

void ordered()
{
	while (BQ.size())
	{
		int x = BQ.front() >> 11, y = BQ.front() & 0x7ff;
		BQ.pop();
		R = max(R, o[x][y]);
		for (int i = 4; i--;)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (arr[nx][ny] != 'X' || o[nx][ny]) continue;
			o[nx][ny] = o[x][y] + 1;
			BQ.push((nx << 11) | ny);
		}
	}
}

bool bfs(int l)
{
	queue<int> Q;
	Q.push(a);
	memset(v, 0, sizeof(v));
	v[a >> 11][a & 0x7ff] = 1;
	while (Q.size())
	{
		if (Q.front() == b) return true;
		int x = Q.front() >> 11, y = Q.front() & 0x7ff;
		Q.pop();

		for (int i = 4; i--;)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (arr[nx][ny] == 0 || v[nx][ny] || o[nx][ny] > l) continue;

			v[nx][ny] = 1;
			Q.push((nx << 11) | ny);
		}
	}

	return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 1; i <= r; i++)
	{
		cin >> arr[i] + 1;
		for (int j = 1; j <= c; j++)
		{
			if (arr[i][j] == 'L')
			{
				if (a == 0) a = (i << 11) | j;
				else b = (i << 11) | j;
				arr[i][j] = '.';
			}
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (!v[i][j] && arr[i][j] == '.')
			{
				queueing(i, j);
			}
		}
	}

	ordered();
	int ans = 1e9;
	while (L <= R)
	{
		int mid = L + R >> 1;
		if (bfs(mid))
		{
			ans = min(ans, mid);
			R = mid - 1;
		}
		else L = mid + 1;
	}

	cout << ans;
}