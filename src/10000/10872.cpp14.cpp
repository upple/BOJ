#include<cstdio>
#include<string>
using namespace std;

int main()
{
	int ans = 1;
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
		ans *= i;

	printf("%d\n", ans);
	return 0;
}