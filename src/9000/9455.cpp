#include <stdio.h>
int main()
{
	int t;
	bool arr[100][100] = {};
	scanf("%d", &t);
	while (t--)
	{
		int n, m, ans=0;
		scanf("%d %d", &n, &m);
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &arr[i][j]);

		for (int i = 0; i < m; i++)
		{
			int pos = n - 1;
			for (int j = n - 1; j >= 0; j--)
				if (arr[j][i])
					ans += (pos--) - j;
		}

		printf("%d\n", ans);
	}
}