#include <cstdio>

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int main()
{
	char arr[1002][1002] = {};
	int n;
	scanf("%d", &n);
	scanf("%s", (arr[1] + 1));

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int count = 0;
			for (int k = 0l; k < 4; k++)
			{
				int nx = i + dx[k], ny = j + dy[k];
				if (arr[nx][ny] == '#')
					count++;
			}

			arr[i + 1][j] = (count % 2 ? '#' : '.');
		}
	}

	for (int i = 1; i <= n; i++)
		printf("%s\n", arr[i] + 1);
}