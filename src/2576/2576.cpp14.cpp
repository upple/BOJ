#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int sum = 0, ans = 101, num;
	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &num);
		if (num % 2)
			sum += num, ans = min(ans, num);

	}
	if (ans == 101)
		printf("-1\n");

	else
		printf("%d\n%d\n", sum, ans);
	return 0;
}
