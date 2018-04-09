#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, pair<int, int> > id;

int main()
{
	int n, k, grade=0;
	 id arr[1001];
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
	{
		int num, g, s, b;
		scanf("%d %d %d %d", &num, &g, &s, &b);
		arr[i] = { {-g, -s}, {-b, num} };
	}

	sort(arr+1, arr + n+1);
	id *cur;
	for (int i = 1; i <= n; i++)
	{
		cur = &arr[i-1];
		cur->second.second = arr[i].second.second;
		if (*cur != arr[i])
			grade=i;

		if (k == arr[i].second.second)
		{
			printf("%d", grade);
			return 0;
		}
	}
}