#include <cstdio>
using namespace std;

int main()
{
	char num[4];
	int n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", num);
		printf("%d\n", num[0]+num[2]-2*('0'));
	}

	return 0;
}
