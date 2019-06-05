#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> p(n + 1, -1);
	while (m--)
	{
		int o, a, b;
		scanf("%d %d %d", &o, &a, &b);

		int pos = a;
		while (p[pos] != -1 && p[pos]!=pos)
			pos = p[pos];

		p[a] = pos;
		pos = b;

		while (p[pos] != -1 && p[pos]!=pos)
			pos = p[pos];

		p[b] = pos;

		if (o)
			printf("%s\n", (p[a] == p[b] ? "YES" : "NO"));

		else if(a!=b)
		{
			if (p[a] > p[b])
				p[p[a]] = p[b];

			else
				p[p[b]] = p[a];
		}
	}
}
