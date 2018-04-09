#include<cstdio>

int main()
{
	int n, m, time = 0;
	scanf("%d %d", &n, &m);
	n--;
	while (m--)
	{
		int t;
		char ans;
		scanf("%d %c", &t, &ans);
		if ((time += t) > 210)
		{
			printf("%d", n + 1);
			return 0;
		}

		if (ans == 'T')
			n = (n + 1) % 8;

	}
}