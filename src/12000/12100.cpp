#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans;
typedef vector<vector<int> > mat;

void dfs(int cnt, mat &arr)
{
	if (cnt == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ans = max(ans, arr[i][j]);
			}
		}

		return;
	}

	mat tmp = arr;
	for (int i = 0; i < n; i++)
	{
		int cur = 0;
		for (int j = 1; j < n; j++)
		{
			if (!tmp[i][j])
				continue;
			
			if (tmp[i][cur])
			{
				if (tmp[i][cur] == tmp[i][j])
					tmp[i][cur++] *= 2, tmp[i][j] = 0;

				else
					swap(tmp[i][++cur], tmp[i][j]);
			}

			else
				swap(tmp[i][cur], tmp[i][j]);

		}

	}

	dfs(cnt + 1, tmp);
	tmp = arr;
	for (int j = 0; j < n; j++)
	{
		int cur = 0;
		for (int i = 1; i < n; i++)
		{
			if (!tmp[i][j])
				continue;

			if (tmp[cur][j])
			{
				if (tmp[cur][j] == tmp[i][j])
					tmp[cur++][j] *= 2, tmp[i][j] = 0;

				else
					swap(tmp[++cur][j], tmp[i][j]);
			}

			else
				swap(tmp[cur][j], tmp[i][j]);

		}

	}

	dfs(cnt + 1, tmp);
	tmp = arr;
	for (int i = 0; i < n; i++)
	{
		int cur = n - 1;
		for (int j = n - 2; j >= 0; j--)
		{
			if (!tmp[i][j])
				continue;

			if (tmp[i][cur])
			{
				if (tmp[i][cur] == tmp[i][j])
					tmp[i][cur--] *= 2, tmp[i][j] = 0;

				else
					swap(tmp[i][--cur], tmp[i][j]);
			}

			else
				swap(tmp[i][cur], tmp[i][j]);

		}

	}

	dfs(cnt + 1, tmp);
	tmp = arr;
	for (int j = 0; j < n; j++)
	{
		int cur = n - 1;
		for (int i = n - 2; i >= 0; i--)
		{
			if (!tmp[i][j])
				continue;

			if (tmp[cur][j])
			{
				if (tmp[cur][j] == tmp[i][j])
					tmp[cur--][j] *= 2, tmp[i][j] = 0;

				else
					swap(tmp[--cur][j], tmp[i][j]);
			}

			else
				swap(tmp[cur][j], tmp[i][j]);

		}

	}

	dfs(cnt + 1, tmp);
}
int main()
{
	scanf("%d", &n);
	mat arr(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	dfs(0, arr);
	printf("%d", ans);
}