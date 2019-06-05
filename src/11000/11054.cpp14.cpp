#include<cstdio>
#include<vector>
#include<algorithm>

#define max(x, y) (x>y?x:y)
using namespace std;

int main()
{
	int n, ans=0;
	vector<int> dp1, dp2;
	scanf("%d", &n);

	vector<int>data(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);

	for (int k = 0; k < n; k++)
	{
		dp1.push_back(-1), dp2.push_back(-1);
		for (int i = 0; i <= k; i++)
		{
			if (dp1.back() < data[i])
				dp1.push_back(data[i]);

			else
				*(lower_bound(dp1.begin(), dp1.end(), data[i])) = data[i];
		}

		for (int i = n-1; i >= k; i--)
		{
			if (dp2.back() < data[i])
				dp2.push_back(data[i]);

			else
				*(lower_bound(dp2.begin(), dp2.end(), data[i])) = data[i];
		}

		ans = max(ans, dp1.size() + dp2.size() - 3);
		dp1.clear(), dp2.clear();
	}

	printf("%d\n", ans);
	return 0;
}