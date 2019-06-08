#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, num;
	vector<int>ans;
	scanf("%d %d", &n, &num);
	ans.push_back(num);
	n--;
	while (n--)
	{
		scanf("%d", &num);
		if (ans.back() < num)
			ans.push_back(num);

		else
			*(lower_bound(ans.begin(), ans.end(), num)) = num;
	}

	printf("%d", ans.size());
}