#include <cstdio>
#include <queue>
#define INF 99999999
using namespace std;
struct xy { int x, y; };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int dp[101][101][4], w, h;
bool inQ[101][101][4];
char map[102][102];
xy Start, End;

void reset()
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				dp[i][j][k] = INF;
			}

		}
	}
}
int bell()
{
	queue<pair<xy, int> > Q;
	for (int i = 0; i < 4; i++)
	{
		dp[Start.x][Start.y][i] = 0;
		inQ[Start.x][Start.y][i] = 1;
		Q.push({ {Start.x, Start.y}, i });
	}

	while (Q.size())
	{
		xy cur = Q.front().first;
		int d = Q.front().second;
		inQ[cur.x][cur.y][d] = 0;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			int cost = (d == i ? 0 : 1);

			if (map[nx][ny] != '.' && map[nx][ny] != 'C')
				continue;

			if (dp[nx][ny][i] > dp[cur.x][cur.y][d] + cost)
			{
				dp[nx][ny][i] = dp[cur.x][cur.y][d] + cost;
				if (!inQ[nx][ny][i])
					inQ[nx][ny][i] = 1, Q.push({ {nx, ny}, i });
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < 4; i++)
	{
		if (ans > dp[End.x][End.y][i])
			ans = dp[End.x][End.y][i];
	}

	return ans;
}
int main()
{
	scanf("%d %d", &w, &h);
	reset();
	bool chk = 0;
	for (int i = 1; i <= h; i++)
	{
		scanf("%s", map[i] + 1);
		for (int j = 1; j <= w; j++)
		{
			if (map[i][j] == 'C')
			{
				if (!chk)
				{
					Start = { i, j };
					chk = 1;
				}
				else
					End = { i, j };
			}
		}
	}

	printf("%d", bell());
}