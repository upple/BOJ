#include <cstdio>
int arr[30];

bool check(int n, int d)
{
	int cnt = 0;
	while (n)
	{
		arr[cnt++] = n % d;
		n /= d;
	}

	for (int i = 0; i < cnt / 2; i++)
	{
		if (arr[i] != arr[cnt - i - 1])
			return false;
	}

	return true;
}
int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);
		bool c = 0;
		for (int i = 2; i <= 64; i++)
		{
			if (check(n, i))
			{
				puts("1");
				c = 1;
				break;
			}
		}

		if (!c)
			puts("0");
	}
}