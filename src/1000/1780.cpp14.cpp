#include <cstdio>
#include <unordered_map>
using namespace std;

unordered_map<int, int>M;
int arr[2187][2187];
void dq(int x, int y, int n)
{
	int t = arr[x][y];
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (arr[i][j] != t)
			{
				for (int k = x; k < x+n; k += n / 3 + n % 3)
					for (int l = y; l < y+n; l += n / 3 + n % 3)
						dq(k, l, n / 3);

				return;
			}
		}
	}

	M[t]++;
}
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	dq(0, 0, n);
	printf("%d\n%d\n%d", M[-1], M[0], M[1]);
}