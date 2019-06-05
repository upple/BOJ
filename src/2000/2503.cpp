#include <cstdio>
#include <cmath>
using namespace std;

int ans = 504;
bool arr[1000];
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (j == i) continue;
			for (int k = 1; k <= 9; k++)
			{
				if (k == j || k == i) continue;
				arr[i * 100 + j * 10 + k] = 1;
			}
		}
	}

	while (n--)
	{
		int q, s, b;
		scanf("%d %d %d", &q, &s, &b);

		for(int i=123; i<1000; i++)
		{
			if (!arr[i]) continue;
			int ss = 0, bb = 0;
			for (int j = 0; j < 3; j++)
			{
				int a = (i % (int)pow(10, j + 1)) / (int)pow(10, j);
				for (int k = 0; k < 3; k++)
				{
					int b = (q % (int)pow(10, k + 1)) / (int)pow(10, k);
					if (a == b)
					{
						if (j == k)
							ss++;

						else
							bb++;
					}
				}
			}
			if (s != ss || b != bb)
				ans--, arr[i] = 0;

		}

	}

	printf("%d", ans);
}