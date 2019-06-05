#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	vector<pair<int, int> > V;
	scanf("%d %d", &n, &m);

	while(m--)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		V.push_back({x, y});
	}

	sort(V.begin(), V.end());
	int ans=0, cur=0;
	for(auto &i : V)
	{
		if(cur<i.first)
		{
			ans+=i.first-cur;
			cur=i.second;
		}

		else if(cur<i.second)
		{
			cur=i.second;
		}

	}

	ans+=n-cur;
	printf("%d", ans);
}
