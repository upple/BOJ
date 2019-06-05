#include<cstdio>

using namespace std;
int main()
{
	int n, num, score=0, ans=0;
	scanf("%d", &n);

	while (n--)
	{
		scanf("%d", &num);
		if (num)
			ans += (++score);

		else
			score = 0;
	}

	printf("%d\n", ans);
	return 0;
}