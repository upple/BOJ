#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, m;
	vector<int> basket;

	basket.push_back(0);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		basket.push_back(i);

	for (int i = 0; i < m; i++)
	{
		int start, end, mid;
		scanf("%d %d %d", &start, &end, &mid);
		vector<int>temp(basket.begin() + start, basket.begin() + mid);
		basket.insert(basket.begin() + end + 1, temp.begin(), temp.end());
		basket.erase(basket.begin() + start, basket.begin() + mid);
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", basket[i]);

	printf("\n");
	return 0;
}
