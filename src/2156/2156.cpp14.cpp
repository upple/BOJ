#include<cstdio>
#include<vector>
#define max(x, y) (x>y?x:y)
using namespace std;

int main()
{
	int n, wine, ans;
	scanf("%d %d", &n, &wine);
	vector<int> dp1(n+1), dp2(n+1);
	dp1[0] = dp2[0] = 0;
	dp1[1] = dp2[1] = wine;
	scanf("%d", &wine);
	dp1[2] = dp2[1] + wine;
	dp2[2] = max(dp1[0], dp2[0])+wine;
	for (int i = 3; i <= n; i++)
	{
		scanf("%d", &wine);
		dp1[i] = dp2[i - 1] + wine;
		dp2[i] = max(max(dp1[i - 2], dp2[i - 2]), max(dp1[i - 3], dp2[i - 3]))+wine;
	}

	ans = max(max(dp1[n], dp1[n-1]), dp2[n]);
	printf("%d", ans);
	return 0;
}
