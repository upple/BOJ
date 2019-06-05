#include <cstdio>
#include <cstring>
int main()
{
	bool num[21] = { 0 };
	int m;
	scanf("%d", &m);
	while (m--)
	{
		char cmd[7];
		int x;
		scanf("%s", cmd);
		if (!strcmp(cmd, "add"))
		{
			scanf("%d", &x);
			if(!num[x])
				num[x] = true;
		}

		else if (!strcmp(cmd, "remove"))
		{
			scanf("%d", &x);
			if (num[x])
				num[x] = false;
		}

		else if (!strcmp(cmd, "check"))
		{
			scanf("%d", &x);
			printf("%d\n", num[x]);
		}

		else if (!strcmp(cmd, "toggle"))
		{
			scanf("%d", &x);
			num[x] = !num[x];
		}

		else if (!strcmp(cmd, "all"))
		{
			for (int i = 1; i <= 20; i++)
				num[i] = true;
		}

		else if (!strcmp(cmd, "empty"))
		{
			for (int i = 1; i <= 20; i++)
				num[i] = false;
		}
	}
}