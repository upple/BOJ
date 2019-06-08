#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
using namespace std;
int main()
{
	char num[33];
	int c, ans=0;
	scanf("%s %d", num, &c);
	int size = strlen(num);
	for (int i = 0; num[i]; i++)
	{
		int temp;
		if (isupper(num[i]))
			temp = num[i] - 'A' + 10;

		else
			temp = num[i] - '0';
		ans += temp*(int)pow(c, size - i-1);
	}
		
	printf("%d", ans);
}