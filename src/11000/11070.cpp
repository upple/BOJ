#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		float MAX=0, MIN=111;
		float w[1001]={}, l[1001]={};
		scanf("%d %d", &n, &m);
		while(m--)
		{
			int a, b, p, q;
			scanf("%d %d %d %d", &a, &b, &p, &q);
			w[a]+=p, l[a]+=q;
			w[b]+=q, l[b]+=p;
		}

		for(int i=1; i<=n; i++)
		{
			w[i]*=w[i], l[i]*=l[i];
			float temp;
			temp=(w[i]+l[i]==0?0:w[i]/(w[i]+l[i]));
			MAX=max(MAX, temp);
			MIN=min(MIN, temp);
		}

		printf("%d\n%d\n", (int)(MAX*1000), (int)(MIN*1000));
	}
}
