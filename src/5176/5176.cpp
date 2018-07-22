#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int p, m, count=0;
		int seat[501]={};
		scanf("%d %d", &p, &m);

		for(int i=0; i<p; i++)
		{
			int num;
			scanf("%d", &num);
			if(!seat[num])
				seat[num]=1, count++;
		}

		printf("%d\n", p-count);
	}
}
