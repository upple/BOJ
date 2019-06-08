#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, ans;
typedef vector<vector<int> > mat;

void dfs(int cnt, int var, mat &arr)
{
	ans = max(ans, var);
	int exp = var * (int)pow(2, 10 - cnt);

	if (cnt == 10 || ans >= exp)
		return;

	mat tmp = arr;
	bool chk = 0;
	int tvar = var;
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
					tvar=max(tvar, tmp[i][cur++] *= 2), tmp[i][j] = 0, chk = 1;

				else
				{
					swap(tmp[i][++cur], tmp[i][j]);
					if (cur != j)
						chk = 1;
				}
			}

			else
				swap(tmp[i][cur], tmp[i][j]), chk = 1;

		}

	}

	if(chk)
		dfs(cnt + 1, tvar, tmp);
	tmp = arr;
	chk = 0, tvar = var;
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
					tvar = max(tvar, tmp[cur++][j] *= 2), tmp[i][j] = 0, chk = 1;

				else
				{
					swap(tmp[++cur][j], tmp[i][j]);
					if (cur != j)
						chk = 1;
				}
			}

			else
				swap(tmp[cur][j], tmp[i][j]), chk = 1;

		}

	}

	if (chk)
		dfs(cnt + 1, tvar, tmp);
	tmp = arr;
	chk = 0, tvar = var;
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
					tvar = max(tvar, tmp[i][cur--] *= 2), tmp[i][j] = 0, chk = 1;

				else
				{
					swap(tmp[i][--cur], tmp[i][j]);
					if (cur != j)
						chk = 1;
				}
			}

			else
				swap(tmp[i][cur], tmp[i][j]), chk = 1;

		}

	}

	if (chk)
		dfs(cnt + 1, tvar, tmp);
	tmp = arr;
	chk = 0, tvar = var;
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
					tvar = max(tvar, tmp[cur--][j] *= 2), tmp[i][j] = 0, chk = 1;

				else
				{
					swap(tmp[--cur][j], tmp[i][j]);
					if (cur != j)
						chk = 1;
				}
			}

			else
				swap(tmp[cur][j], tmp[i][j]), chk = 1;

		}

	}

	if (chk)
		dfs(cnt + 1, tvar, tmp);
}
int main()
{
	scanf("%d", &n);
	int var=0;
	mat arr(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
			var = max(var, arr[i][j]);
		}
	}

	dfs(0, var, arr);
	printf("%d", ans);
}