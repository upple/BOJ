#include <cstdio>
#include <set>
using namespace std;
set<int> P, Q;
int main()
{
	int p, q, num;
	scanf("%d %d", &p, &q);

	for (int i = 1; i*i <= p; i++)
	{
		if (!(p%i))
			P.insert(i), P.insert(p / i);
	}

	for (int i = 1; i*i <= q; i++)
	{
		if (!(q%i))
			Q.insert(i), Q.insert(q / i);
	}

	for (auto i : P)
	{
		for (auto j : Q)
		{
			printf("%d %d\n", i, j);
		}
	}
}