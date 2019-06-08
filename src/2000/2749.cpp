#include <cstdio>
#define MOD 1000000;
class Mat
{
public:
	long long arr[2][2];
	Mat()
	{
		arr[0][0] = arr[0][1] = arr[1][0] = arr[1][1] = 0;
	}

	Mat operator * (const Mat &a)
	{
		Mat mul;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					mul.arr[i][j] = (mul.arr[i][j] + arr[i][k] * a.arr[k][j]) % MOD;
				}
			}
		}

		return mul;
	}

	void operator = (const Mat &a)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				arr[i][j] = a.arr[i][j];
			}
		}
	}
};
int main()
{
	Mat tmp, ans;
	long long n;
	scanf("%lld", &n);
	tmp.arr[0][0] = tmp.arr[1][0] = tmp.arr[0][1] = ans.arr[0][0] = ans.arr[1][1] = 1;

	while (n)
	{
		if (n & 1)
		{
			ans = ans * tmp;
		}

		tmp = tmp * tmp;
		n >>= 1;
	}

	printf("%lld", ans.arr[1][0]);
}