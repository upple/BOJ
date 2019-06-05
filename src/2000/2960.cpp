#include <cstdio>

int main()
{
	int n, k, count = 0, ans=0;
	bool arr[1001] = {};
	scanf("%d %d", &n, &k);
	
	for (int i = 2; i <= n && !ans; i++)
	{
		if (!arr[i])
		{
			int temp = i;
			while (temp <= n)
			{
				if (!arr[temp])
				{
					if (++count == k)
					{
						ans = temp;
						break;
					}
					arr[temp] = true;
				}
				temp += i;
			}
		}
	}
	printf("%d", ans);
}