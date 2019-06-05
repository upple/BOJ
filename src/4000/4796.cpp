#include <cstdio>
#include <algorithm>
int main()
{
	int t=0;
	while(++t)
	{
		int l, p, v;
		scanf("%d %d %d", &l, &p, &v);
		if(!l) return 0;
		printf("Case %d: %d\n", t, l*(v/p)+std::min(v%p, l));
	}


}
