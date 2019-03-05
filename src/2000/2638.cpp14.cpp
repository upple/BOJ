#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
bool map[100][100], v[100][100];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
struct xy{ int x, y; };

void bfs_air()
{
	memset(v, 0, 100 * 100);
	queue<xy> Q;
	Q.push({ 0, 0 });
	v[0][0] = 1;
	while (Q.size())
	{
		int x = Q.front().x, y = Q.front().y;
		Q.pop();
		for (int i = 4; i--;)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || v[nx][ny] || map[nx][ny]) continue;
			Q.push({ nx, ny });
			v[nx][ny] = 1;
		}
	}
	
}

bool bfs_melt()
{
	bool chk = true;
	bool visit[100][100] = {};
	queue<xy> melt;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] && !visit[i][j])
			{
				queue<xy> Q;
				Q.push({ i, j });
				visit[i][j] = 1;
				while (Q.size())
				{
					int x = Q.front().x, y = Q.front().y;
					Q.pop();
					int chk = 0;
					for (int i = 4; i--;)
					{
						int nx = x + dx[i], ny = y + dy[i];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (map[nx][ny] == 1)
						{
							if (!visit[nx][ny])
							{
								Q.push({ nx, ny });
								visit[nx][ny] = 1;
							}
						}
						else if (map[nx][ny] == 0 && v[nx][ny])
						{
							chk++;
						}
					}

					if (chk >= 2) melt.push({ x, y });
				}
			}
		}
	}

	if (melt.empty()) return true;
	while (melt.size())
	{
		int x = melt.front().x, y = melt.front().y;
		melt.pop();
		map[x][y] = 0;
	}
	return false;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	int cnt = -1;
	do
	{
		cnt++;
		bfs_air();
	} while (!bfs_melt());

	cout << cnt;
}