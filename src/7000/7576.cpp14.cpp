#include<cstdio>
#include<queue>

using namespace std;

const int move_x[4] = { 0, 0, 1, -1 };
const int move_y[4] = { 1, -1, 0, 0 };

int box[1000][1000] = {};
class xy
{
public:
	int x, y;
	xy(int a, int b) :x(a), y(b) {}
};
int main()
{
	int n, m, count = 0, ripe=0, unripe=0;
	queue<xy>Queue;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1)
				Queue.push(xy(i, j)), ripe++;

			else if (box[i][j] == 0)
				unripe++;
		}

	if (!unripe)
	{
		printf("0\n");
		return 0;
	}

	Queue.push(xy(-1, -1));
	while (!Queue.empty())
	{
		xy pos = Queue.front();
		Queue.pop();

		if (pos.x == -1)
		{
			if (!Queue.empty())
			{
				count++;
				Queue.push(xy(-1, -1));
				continue;
			}

			else
				break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = pos.x + move_x[i], ny = pos.y + move_y[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !box[nx][ny])
				unripe--, box[nx][ny] = 1, Queue.push(xy(nx, ny));

		}


	}

	if (unripe)
		printf("-1\n");

	else
		printf("%d\n", count);


}
