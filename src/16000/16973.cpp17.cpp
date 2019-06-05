#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };
bool arr[1001][1001], v[1001][1001];
int n, m;
int h, w, sr, sc, fr, fc;

int bfs()
{
	queue<int> Q;
	v[sr][sc] = 1;
	Q.push((sr << 10) + sc);
	int time = 0;
	while (Q.size())
	{
		for (int size = Q.size(); size--;)
		{
			int x = Q.front() >> 10, y = Q.front() & 0x3ff;
			Q.pop();
			if (x == fr && y == fc) return time;
			for (int u = 4; u--;)
			{
				int nx = x + dx[u], ny = y + dy[u];
				bool chk = true;
				switch (u)
				{
				case 0:
					if (ny + w > m || v[nx][ny])
					{
						chk = false;
						break;
					}
					v[nx][ny] = 1;
					for (int i = 0; i <= h; i++)
					{
						if (arr[nx + i][ny + w])
						{
							chk = false;
							break;
						}
					}
					break;
				case 1:
					if (ny <= 0 || v[nx][ny])
					{
						chk = false;
						break;
					}
					v[nx][ny] = 1;
					for (int i = 0; i <= h; i++)
					{
						if (arr[nx + i][ny])
						{
							chk = false;
							break;
						}
					}
					break;
				case 2:
					if (nx + h > n || v[nx][ny])
					{
						chk = false;
						break;
					}
					v[nx][ny] = 1;
					for (int i = 0; i <= w; i++)
					{
						if (arr[nx + h][ny + i])
						{
							chk = false;
							break;
						}
					}
					break;
				case 3:
					if (nx <= 0 || v[nx][ny])
					{
						chk = false;
						break;
					}
					v[nx][ny] = 1;
					for (int i = 0; i <= w; i++)
					{
						if (arr[nx][ny + i])
						{
							chk = false;
							break;
						}
					}
					break;
				}

				if (chk == false) continue;
				Q.push((nx << 10) + ny);
			}
		}
		time++;
	}
	return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cin >> h >> w >> sr >> sc >> fr >> fc;
	h--, w--;
	cout << bfs();
}