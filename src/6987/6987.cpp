#include <iostream>
using namespace std;
int res[6][3], cur[6][3];
int solve(int a, int b)
{
	if (b == 6)
	{
		a++;
		b = a + 1;
	}
	if (a==5)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (res[i][j] != cur[i][j])
					return 0;
			}
		}

		return 1;
	}

	for (int k = 0; k < 3; k++)
	{
		cur[a][k]++, cur[b][2 - k]++;
		if (solve(a, b + 1))
			return 1;

		cur[a][k]--, cur[b][2 - k]--;
	}
	
	return 0;
}

int main()
{
	int t = 4;
	while (t--)
	{
		int sum = 0;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> res[i][j];
				sum += res[i][j];
				cur[i][j] = 0;
			}
		}

		if (sum != 30)
			cout << 0;

		else
			cout << solve(0, 1);

		if (t)
			cout << " ";
	}

}