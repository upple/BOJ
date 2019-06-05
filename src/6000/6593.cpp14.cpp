#include<cstdio>
#include<queue>
using namespace std;

const int move_x[6] = { 0, 0, 0, 0, -1, 1 };
const int move_y[6] = { 0, 0, -1, 1, 0, 0 };
const int move_z[6] = { -1, 1, 0, 0, 0, 0 };
char bilding[30][30][31];
int l, r, c;

class xyz
{
public:
	int x, y, z;
	xyz(int l=0, int r=0, int c=0) : x(r), y(c), z(l) {}
	xyz & operator = (const xyz & a)
	{
		x=a.x, y=a.y, z=a.z;
		return *this;
	}
};

int bfs(xyz pos)
{
	int count = 0;
	queue<xyz> Queue;
	Queue.push(pos);
	bilding[pos.z][pos.x][pos.y] = '#';
	Queue.push(xyz(-1));
	while (1)
	{
		pos = Queue.front();
		Queue.pop();

		if (pos.z == -1)
		{
			if (Queue.empty())
				return -1;

			count++, Queue.push(xyz(-1));
			continue;
		}

		if (bilding[pos.z][pos.x][pos.y] == 'E')
			return count;

		for (int i = 0; i < 6; i++)
		{
			int nx = pos.x + move_x[i], ny = pos.y + move_y[i], nz = pos.z + move_z[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c && nz >= 0 && nz < l && bilding[nz][nx][ny] != '#')
			{
				if(bilding[nz][nx][ny]=='.')
					bilding[nz][nx][ny] = '#';

				Queue.push(xyz(nz, nx, ny));
			}
		}
	}
}
int main()
{
	int  ans;
	xyz start;
	while (1)
	{
		scanf("%d %d %d", &l, &r, &c);
		if (l == 0)
			break;
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				scanf("%s", bilding[i][j]);
				for (int k = 0; k < c; k++)
				{
					if (bilding[i][j][k] == 'S')
						start = xyz(i, j, k);
				}
			}
		}

		ans = bfs(start);
		if (ans == -1)
			printf("Trapped!\n");

		else
			printf("Escaped in %d minute(s).\n", ans);

	}

	return 0;
}