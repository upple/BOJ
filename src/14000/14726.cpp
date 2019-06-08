#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char num[17], ans=0;
		scanf("%s", num);
		for(int i=0; i<16; i++)
		{
			int k=num[i]-'0';
			ans+=(i%2?k:(k*2)/10+(k*2)%10);
		}

		printf("%c\n", (ans%10?'F':'T'));
	}

}
