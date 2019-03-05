#include <cstdio>
#include <queue>
using namespace std;
struct state { int m, c; };
bool v[1001][1001];
int main()
{
	int n, cnt = 0;
	queue<state> Q;
	scanf("%d", &n);

	Q.push({ 1, 0 });
	v[1][0] = 1;
	while (Q.size())
	{
		int size = Q.size();
		while (size--)
		{
			int m = Q.front().m, c = Q.front().c;
			Q.pop();

			if (m == n)
			{
				printf("%d", cnt);
				return 0;
			}

			if (m + c <= 1000 && !v[m + c][c])
			{
				v[m + c][c] = 1;
				Q.push({ m + c, c });
			}

			if(m <= 1000 && !v[m][m])
			{
				v[m][m] = 1;
				Q.push({ m, m });
			}

			if (m && !v[m - 1][c])
			{
				v[m - 1][c] = 1;
				Q.push({ m - 1, c });
			}
		}

		cnt++;
	}
}