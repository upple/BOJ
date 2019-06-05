#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char number[81];
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", number);		
		printf("%s\n", (next_permutation(number, number + strlen(number))?number:"BIGGEST"));
	}
}