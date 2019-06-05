#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int p[500000];
int main()
{
	int n, m, c, c1, c2, num;
	map<int, int> M;
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	c=abs(c1-c2);
	for(int i=0; i<n; i++)
		scanf("%d", &p[i]);

	sort(p, p+n);
	for(int i=0; i<m; i++)
	{
		scanf("%d", &num);
		int *pick=lower_bound(p, p+n, num);
		if(pick==p)
			M[*pick-num]++;

		else if(pick==p+n)
			M[num-*(--pick)]++;

		else
		{
			int a=abs(num-*(pick)), b=abs(num-*(pick-1));
			if(a==b)
				M[a]+=2;

			else
				M[min(a, b)]++;

		}
	}

	printf("%d %d", M.begin()->first+c, M.begin()->second);
}
