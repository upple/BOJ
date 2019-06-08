#include <cstdio>

int main()
{
	int n, c, ans=0;
	bool arr[2000001] = {};
	scanf("%d %d", &n, &c);

	for (int i = 0; i < n; i++)
	{
		int p;
		scanf("%d", &p);
		if (!arr[p])
		{
			int temp = 0;
			while ((temp+=p) <= c)
			{
				if (!arr[temp])
					ans++, arr[temp] = true;
			}
		}
	}

	printf("%d", ans);
}