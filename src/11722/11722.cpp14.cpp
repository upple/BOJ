#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> dp;
	dp.push_back(1231231231);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		if (dp.back() < -num)
			dp.push_back(-num);

		else
			*(lower_bound(dp.begin(), dp.end(), -num)) = -num;
	}
	printf("%d\n", dp.size());
	return 0;
}