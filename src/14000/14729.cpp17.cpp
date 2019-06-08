#include <cstdio>
#pragma GCC optimize("O3")
float t;
#define SWAP(a, b) {t=(a); a=(b); b=t;}
int main()
{
	int n;
	scanf("%d", &n);
	float ans[8]={1e9f, 1e9f, 1e9f, 1e9f, 1e9f, 1e9f, 1e9f, };
	while(n--)
	{
		scanf("%f", &ans[7]);
		for(int i=7; i--;)
		{
			if(ans[i+1]>=ans[i]) break;
			SWAP(ans[i+1], ans[i]);
		}

	}
	
	for(int i=0; i<7; i++)
		printf("%.3f\n", ans[i]);
}