#include<cstdio>
#include<queue>

using namespace std;

const int move_x[4] = { 0, 0, 1, -1 };
const int move_y[4] = { 1, -1, 0, 0 };

class xy
{
public:
	int x, y;
	xy(int a, int b) :x(a), y(b) {}
};

char map[27][27] = {};
int bfs(int x, int y)
{
	queue<xy>Queue;
	int count = 0;
	Queue.push(xy(x, y));
	while (!Queue.empty())
	{
		xy pos = Queue.front();
		Queue.pop();
		count++;
		for (int i = 0; i < 4; i++)
		{
			int nx = pos.x + move_x[i], ny = pos.y + move_y[i];
			if (map[nx][ny]=='1')
				map[nx][ny] = '0', Queue.push(xy(nx, ny));
		}
	}

	return count;
}
int main()
{
	int n;
	priority_queue<int, vector<int>, greater<int> > sorted;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%s", map[i]+1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == '1')
				map[i][j]='0', sorted.push(bfs(i, j));
		}

	}

	printf("%d\n", sorted.size());
	for (int i = 0; !sorted.empty(); i++)
		printf("%d\n", sorted.top()), sorted.pop();

}
