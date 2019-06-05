#include <cstdio>
const int MOD = 31991;

int d, t;
class arr
{
public:	
	int M[50][50];
	arr()
	{
		for (int i = 0; i < d; i++)
			for (int j = 0; j < d; j++)
				M[i][j] = 0;
	}

	arr operator *(arr &a)
	{
		arr res;
		for (int i = 0; i < d; i++)
			for (int j = 0; j < d; j++)
				for (int k = 0; k < d; k++)
					res.M[i][j] = (res.M[i][j] + (M[i][k] * a.M[k][j])) % MOD;

		return res;
	}

	void operator = (const arr &a)
	{
		for (int i = 0; i < d; i++)
			for (int j = 0; j < d; j++)
				M[i][j] = a.M[i][j];
	}
};

int main()
{
	scanf("%d %d", &d, &t);
	arr s, ans;

	for (int i = 0; i < d; i++)
		s.M[0][i] = s.M[i][(i + 1)%d] = ans.M[i][i] = 1;

	while (t)
	{
		if (t & 1)
			ans = ans * s;

		s = s * s;
		t >>= 1;
	}

	printf("%d", ans.M[0][0]);
}
