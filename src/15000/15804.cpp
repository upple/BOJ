#include <cstdio>
#include <algorithm>

int n, m, c, w, wc, a, b;
int main()
{
	scanf("%d %d", &n, &m);

	while(m--)
	{
		scanf("%d %d", &a, &b);
		if(c==n)
			wc=w, w=c=0;

		if(w<=(a=std::max(a, wc)))
			c=1, w=a+b;

		else
		{
			w=std::max(w, a+b);
			c++;
		}

	}

	printf("%d", c);
}
