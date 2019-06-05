#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	int n, c;
	unordered_map<int, pair<int, int> > M;
	vector < pair<int, pair<int, int> > > arr;

	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);

		if (M[num].first == 0)
			M[num].second = i;

		M[num].first++;
	}

	for (auto &i : M)
		arr.push_back({ -i.second.first, {i.second.second, i.first} });

	sort(arr.begin(), arr.end());

	for(auto &i : arr)
		for(int j=0; j<-i.first; j++)
			printf("%d ", i.second.second);
}