#include <cstdio>

int dp[46];

int getNext(int x)
{
	int tmp = x, n = 0;
	while (tmp)
	{
		n += tmp % 10;
		tmp /= 10;
	}

	return n;
}
int solve(int x)
{
	if (dp[x])
		return dp[x];

	if (x < 10)
		return dp[x] = x;

	return dp[x] = solve(getNext(x));
}
int main()
{
	int n;
	while (1)
	{
		scanf("%d", &n);
		if (!n)
			return 0;

		if (n > 45)
			n = getNext(n);
		printf("%d\n", solve(n));
	}
}