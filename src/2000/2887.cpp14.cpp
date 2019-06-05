#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#define MAX 100000
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
int n;
pli p[3][MAX];
ll arr[MAX][3];
bool v[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll x, y, z;
		cin >> x >> y >> z;
		*arr[i] = x;
		*(arr[i] + 1) = y;
		*(arr[i] + 2) = z;
		p[0][i] = { x, i };
		p[1][i] = { y, i };
		p[2][i] = { z, i };
	}

	sort(p[0], p[0] + n);
	sort(p[1], p[1] + n);
	sort(p[2], p[2] + n);

	priority_queue<pli> pq;
	pq.push({ 0, 0 });
	int remain = n;
	ll ans = 0;
	while (remain)
	{
		int cur = pq.top().second;
		ll cost = -pq.top().first;
		pq.pop();
		if (v[cur]) continue;
		ans += cost;
		remain--;
		v[cur] = 1;
		for (int i = 0; i < 3; i++)
		{
			int it = lower_bound(p[i], p[i] + n, pli(arr[cur][i], cur)) - p[i];
			if (it != 0 && !v[p[i][it - 1].second])
				pq.push({ -(abs(arr[cur][i] - p[i][it - 1].first)), p[i][it - 1].second });

			if (it != n - 1 && !v[p[i][it + 1].second])
				pq.push({ -(abs(arr[cur][i] - p[i][it + 1].first)), p[i][it + 1].second });
		}
	}

	cout << ans;
}