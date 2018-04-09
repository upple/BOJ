#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	bool turn = false; //0 : increase, 1 : decrease
	scanf("%d", &n);
	deque<int> arr(n), sorted, ans;
	deque<pair<int, int> > id;
	ans.push_back(0);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &m);
	id.resize(m);
	for (int i = m - 1; i >= 0; i--)
		scanf("%d %d", &id[i].first, &id[i].second);

	for (int i = 0; i < m; i++)
	{
		if (turn)
		{
			if (ans.front() < id[i].second)
				*ans.begin() = id[i].second;

			if (ans.front() < id[i].first)
				ans.push_front(id[i].first), turn = !turn;
		}
		else
		{
			if (ans.front() < id[i].second)
			{
				ans.push_front(id[i].second), turn = !turn;
				if (id[i].first > id[i].second)
					ans.push_front(id[i].first), turn = !turn;
			}

			else if (ans.front() < id[i].first)
				*ans.begin() = id[i].first;
		}
	}

	auto large = arr.begin() + ans.front();
	auto small = arr.begin();
	sort(small, large);
	for (auto i = ans.begin(); i != ans.end()-1; i++)
	{
		int end = *(i+1);
		if (!turn)
			for (int j = *i - 1; j >= end; j--)
				sorted.push_front(*(--large));
		else
			for (int j = *i - 1; j >= end; j--)
				sorted.push_front(*small++);

		turn = !turn;
	}

	for (auto i = sorted.begin(); i != sorted.end(); i++)
		printf("%d ", *i);

	for (int i = sorted.size(); i<n; i++)
		printf("%d ", arr[i]);
}