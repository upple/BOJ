#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pq.push(x);
	}

	int cnt = 0, ans=999999999;
	while (1)
	{
		int x = pq.top();
		pq.pop();
		if (pq.empty())
		{
			ans = min(ans, cnt + 1);
			break;
		}
		ans = min({ ans, cnt + 1 + pq.top(), cnt + x });
		cnt++;
	}

	cout << ans;
}