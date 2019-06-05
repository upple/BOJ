#include <cstdio>
#include <algorithm>
using namespace std;
pair<double, pair<double, int> > arr[25001];
int main()
{
	int n;
	double ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		double j, p;
		scanf("%lf %lf", &j, &p);
		arr[i] = { -j / p, {p, i} };
	}

	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= 3; i++)
	{
		ans += arr[i].second.first;
	}

	printf("%d\n", (int)ans);
	for (int i = 1; i <= 3; i++)
	{
		printf("%d\n", arr[i].second.second);
	}
}