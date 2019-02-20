#include <stdio.h>

inline int read_int()
{
	int ret=0;
	register bool chk=false;
	register char c;
	while(1)
	{
		c=getchar_unlocked();
		if(c<'0' || c>'9')
		{
			if(chk) break;
			continue;
		}
		chk=true;
		ret=ret*10+c-'0';
	}

	return ret;
}
int main()
{
	register int n=read_int();
	register int a, i;
	register char buffer[10]={};
	while(n--)
	{
		a=read_int();
		a+=read_int();
		for(i=8; a; i--)
		{
			buffer[i]=(a%10)+'0';
			a/=10;
		}

		puts(buffer+i+1);
	}
}