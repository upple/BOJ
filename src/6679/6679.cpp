#include <cstdio>

int main()
{
	for(int i = 2992; i < 10000; i++)
	{
		int a, b, c, d, e, f;
		a = b = c = i;
		d = e = f = 0;
		while (a)
		{
			d += a % 10;
			a /= 10;
		}
		while (b)
		{
			e += b % 12;
			b /= 12;
		}
		while (c)
		{
			f += c % 16;
			c /= 16;
		}

		if (d == e && e == f)
		{
			printf("%d\n", i);
		}
	}
}