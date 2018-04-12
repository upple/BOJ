#include <cstdio>
#include <bitset>

std::bitset<33554433> B;
int main()
{
	long long num;
	while (~scanf("%lld", &num))
	{
		if (!B.test(num))
			printf("%lld ", num), B.set(num, 1);
	}
}