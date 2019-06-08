#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001];
int in[1001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int c, p;
		cin >> c;
		if (c == 0) continue;
		cin >> p;
		for (int i = 1; i < c; i++)
		{
			int nn;
			cin >> nn;
			adj[p].push_back(nn);
			in[nn]++;
			p = nn;
		}
	}
	queue<int> Q, ans;
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) Q.push(i);

	while (Q.size())
	{
		int cur = Q.front();
		ans.push(cur);
		Q.pop();
		for (int i : adj[cur])
		{
			if (!--in[i])
				Q.push(i);
		}
	}

	if (ans.size() != n)
	{
		cout << 0;
		return 0;
	}

	while (ans.size())
	{
		cout << ans.front() << "\n";
		ans.pop();
	}
}