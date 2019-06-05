#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
const double Q = 31;
using namespace std;

int main()
{
	int n = 814;
	int x = -8140, y = -8140;
	bool chk = 0;
	int w = -8140, cnt = 0;
	while (n)
	{
		if (abs(x) <= 8140 && abs(y) <= 8140)
		{
			n--;
			cnt++;
			int nx = x + rand() % 10, ny = y + rand() % 10;
			while (abs(nx) > 8140 || abs(ny) > 8140)
			{
				nx = x + rand() % 10, ny = y + rand() % 10;
			}
			printf("%d %d\n", nx, ny);
		}
		if (chk == 0)
		{
			if (abs(y + sqrt(3) * Q) > 8140)
			{
				x = w += Q*2;
				y = -8140;
				chk = 1;
			}
			else x += Q, y += sqrt(3) * Q;
		}
		else
		{
			if (abs(y + sqrt(3) * Q) > 8140)
			{
				x = w += Q*2;
				y = -8140;
				chk = 1;
			}
			else x -= Q, y += sqrt(3) * Q;
		}

		chk = !chk;
	}
}