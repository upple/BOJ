#include <cstdio>
const int MOD = 1000000007;
class arr
{
public:	
	long long M[2][2];
	arr()
	{
		M[0][0] = M[1][0] = M[0][1] = M[1][1] = 0;
	}

	arr operator *(arr &a)
	{
		arr res;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
					res.M[i][j] = (res.M[i][j] + (M[i][k] * a.M[k][j])) % MOD;

		return res;
	}

	void operator = (const arr &a)
    {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				M[i][j] = a.M[i][j];
	}
};

int main()
{
	int n;
	arr s, ans;
	scanf("%d", &n);
	ans.M[0][0] = ans.M[1][1] = 1;
	s.M[0][0] = s.M[0][1] = s.M[1][0] = 1;
	if (n == 0)
	{
		printf("0");
		return 0;
	}
	n--;
	while (n)
	{
		if (n & 1)
		{
			ans = ans * s;
		}

		s = s * s;
		n >>= 1;
	}

	printf("%lld", ans.M[0][0]);
}
