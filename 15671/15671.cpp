#include <cstdio>
#include <queue>
using namespace std;
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

struct xy
{
	int x, y;
};
int map[7][7];
bool visit[7][7];
int main()
{
	int n, turn = 0;
	scanf("%d", &n);

	int score[2] = { 2, 2 };
	visit[3][3] = visit[3][4] = visit[4][3] = visit[4][4] = 1;
	map[3][3] = map[4][4] = 1;
	while(n--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		visit[x][y] = 1;
		map[x][y] = turn;
		for (int i = 0; i < 8; i++)
		{
			int nx = x, ny = y;
			queue<xy> Q;
			while (1)
			{
				nx += dx[i], ny += dy[i];
				if (!nx || !ny || nx > 6 || ny > 6 || !visit[nx][ny])
					break;

				if (map[nx][ny] == turn)
				{
					score[turn] += Q.size(), score[(turn + 1) % 2] -= Q.size();
					while (Q.size())
						map[Q.front().x][Q.front().y] = turn, Q.pop();

					break;
				}

				else
					Q.push({ nx, ny });
			}
		}
		turn = (turn + 1) % 2;
	}

	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (!visit[i][j])
				printf(".");

			else
				printf("%c", (map[i][j] ? 'W' : 'B'));
		}
		printf("\n");
	}
	printf("%s", score[0] > score[1] ? "Black" : "White");
}