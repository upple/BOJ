#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n, root = 0, s = 10;
		bool check = 1;
		char num[11];
		int arr[1111111] = {};
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%s", num);
			int p = num[0] - '0';
			for (int j = 0; num[j+1] && check; j++)
			{
				switch (arr[p])
				{
				case -1:
					check = 0;
					break;
				case 0:
					arr[p] = s;
					s += 10;
				
				default:
					p = arr[p] + num[j + 1] - '0';
				}
			}
			if (arr[p] != 0)
				check = 0;
			arr[p] = -1;
		}

		puts(check ? "YES" : "NO");
	}
}