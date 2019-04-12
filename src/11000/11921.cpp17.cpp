#include <stdio.h>
#pragma gcc optimize ("O3")

inline long long read_int()
{
	register long long ret=0;
	register int chk=0;
	register char c;
	while(1)
	{
		c=getchar_unlocked();
		if(c<'0' || c>'9')
		{
			if(chk) break;
			continue;
		}
		chk=1;
		ret=ret*10+c-'0';
	}

	return ret;
}
int main()
{
	register int n=read_int();
	if(n>100000) n=100000;
	register int a, i;
	register long long ans=0;
	for(register int i=n; i--;)
	{
		ans+=read_int();
	}
	printf("%d\n%lld", n, ans);
}