#include <cstdio>

bool arr[100001] = {};
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 2; i*i <= n; i++)
	{
		if (!arr[i])
		{
			int temp = i;
			while (temp <= n)
			{
				arr[temp] = 1;
				temp += i;
			}
		}
	}
	printf("%s", arr[n]?"No":"Yes");
}