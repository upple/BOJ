#include <cstdio>

int a[1000000], b[1000000];
int main()
{
	int n, pos;
	bool fnd = true;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		if (b[i] == a[0])
			pos = i;
	}

	for (int i = 1; i < n; i++)
	{
		if (b[(pos + i) % n] != a[i])
		{
			fnd = false;
			break;

		}

	}

	if (fnd == true)
	{
		printf("good puzzle");
		return 0;
	}

	for (int i = 1; i < n; i++)
	{
		if (b[(n+pos - i) % n] != a[i])
		{
			printf("bad puzzle");
			return 0;
		}

	}

	printf("good puzzle");
}