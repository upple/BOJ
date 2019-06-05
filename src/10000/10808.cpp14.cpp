#include<cstdio>
using namespace std;

int main()
{
	int num[26] = { 0, };
	char str[101];
	scanf("%s", str);

	for (int i = 0; str[i]; i++)
		num[str[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		printf("%d ", num[i]);

	return 0;
}
