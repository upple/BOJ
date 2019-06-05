#include <cstdio>
#include <queue>
using namespace std;
struct xy
{
	int d, x, y;
};

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int main()
{
	int n, m, hx, hy, ex, ey, count=0;
	int arr[1001][1001], visit[2][1001][1001] = {};
	scanf("%d %d", &n, &m);
	
	scanf("%d %d %d %d", &hx, &hy, &ex, &ey);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	queue<xy> Q;
	Q.push({ 0, hx, hy });
	Q.push({ -1, -1, -1 });
	visit[0][hx][hy] = 1;
	while (Q.size())
	{
		xy cur = Q.front();
		Q.pop();
		if (cur.d == -1)
		{
			if (Q.empty())
			{
				printf("-1");
				return 0;
			}

			count++, Q.push({ -1, -1, -1 });
			continue;
		}

		if (cur.x == ex && cur.y == ey)
		{
			printf("%d", count);
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m)
			{
				if (cur.d == 1 && !visit[1][nx][ny] && !arr[nx][ny])
					visit[1][nx][ny] = 1, Q.push({ 1, nx, ny });

				else if (cur.d == 0 && !visit[arr[nx][ny]][nx][ny])
					visit[arr[nx][ny]][nx][ny] = 1, Q.push({ arr[nx][ny], nx, ny });
			}
		}
	}
}