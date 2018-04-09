#include <cstdio>
#include <unordered_set>
using namespace std;

int main()
{
	int n;
	unordered_set <int> S;

	scanf("%d", &n);
	
	while(n!=1)
	{
		S.insert(n);
		int next = 0;
		while (n)
		{
			next += (n % 10)*(n % 10);
			n /= 10;
		}

		if (S.find(next) != S.end())
		{
			printf("UNHAPPY");
			return 0;
		}

		n = next;
	}

	printf("HAPPY");
}