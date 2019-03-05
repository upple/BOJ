#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<int, int> M;
int solve(int num)
{
	int &x = M[num];
	if (x)
		return x;
	
	return num % 2 ? max(num, solve(num * 3 + 1)) : max(num, solve(num / 2));
}
int main()
{
	M[1] = 1;
	int n;
	scanf("%d", &n);

	while (n--)
	{
		int num, ans = 0;
		scanf("%d", &num);
		printf("%d\n", solve(num));
	}
}